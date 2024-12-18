# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 05:19:48 by maanton2          #+#    #+#              #
#    Updated: 2024/12/18 19:28:04 by maanton2         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

LIBFT_VERSION		:= 2.2.0
MLX_VERSION			:= 2.4.1
CMAKE_VERSION		:= 3.16
 
# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #
 
SRC_MAIN			:= src/
SRCS_WINDOW			:= src/window/
INCS				:= includes/ lib/libft/includes lib/MLX42/include/ src/window
BUILD_DIR			:= build/
MLX42_DIR			:= lib/MLX42/
SRCS_LIBFT			:= lib/libft/
MLX42_BUILD_DIR		:= lib/MLX42/build/

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#
 
RM					:= rm -rf
MKDIR				:= mkdir -p
 
# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #
 
NAME				:= so_long

MLX42				= $(addprefix $(MLX42_BUILD_DIR), libmlx42.a)
LIBFT				+=$(addprefix $(SRCS_LIBFT), libft.a)
LIBS				:= ./lib/libft/libft.a \
	./lib/MLX42/build/libmlx42.a

SOURCE_FILES		+=$(addprefix $(SRC_MAIN), main.c)

SOURCE_FILES		+=$(addprefix $(SRCS_WINDOW), ft_create_window.c)
 
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(BUILD_DIR)%.o)

OBJECT_FILES_BONUS	:= $(SOURCE_FILES_BONUS:%.c=$(BUILD_DIR)%.o)
 
#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#
 
CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra
CPPFLAGS			:= $(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS				:= $(addprefix -L,$(dir $(LIBS)))
LDLIBS				:= -lft -lmlx42 -ldl -lglfw -pthread -lm -g3
COMP_OBJS			= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE			= $(CC) $(LDFLAGS) $(OBJECT_FILES) $(LDLIBS) -o $(NAME)
 
#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#
 
define submodule_update_libft
	git submodule update --init --remote >/dev/null 2>&1 || true
	git submodule foreach -q \
		'branch="$(git config -f $toplevel/.gitmodules submodule.Libft)"; \
		git pull origin main; \
		git fetch; \
		git checkout v$(LIBFT_VERSION)' \
		>/dev/null 2>&1 || true
	$(SLEEP)
	$(MAKE) -C $(SRCS_LIBFT)
endef
 
define submodule_update_mlx42
	printf "$(PURPLE)Building library MLX42\n$(RESET)"
	git submodule update --init --recursive >/dev/null 2>&1 || true
	git submodule foreach -q --recursive \
		'branch="$(git config -f $toplevel/.gitmodules submodule.MLX42)"; \
		git pull origin master; \
		git fetch; \
		git checkout v$(MLX42_VERSION)' \
		>/dev/null 2>&1 || true
	sed -i 's/3\.18/$(CMAKE_VERSION)/g' $(MLX42_DIR)CMakeLists.txt >/dev/null 2>&1 || true
	$(SLEEP)
	cd $(MLX42_DIR) && cmake -B build -DDEBUG=1 >/dev/null 2>&1 || true
	cd $(MLX42_DIR) && cmake --build build -j4
	cd $(MLX42_DIR) && git restore CMakeLists.txt >/dev/null 2>&1 || true
endef

define create_dir
	$(MKDIR) $(dir $@)
endef
 
define comp_objs
	$(COMP_OBJS)
endef
 
define comp_exe
	@$(COMPILE_EXE)
endef
 
define clean
	$(RM) $(OBJECT_FILES) $(OBJECT_FILES_BONUS)
endef
 
define fclean
	$(RM) $(NAME)
	$(RM) $(BUILD_DIR)
endef
 
#******************************************************************************#
#                                   RULES                                      #
#******************************************************************************#
 
all: $(LIBFT) $(MLX42) $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)
 
$(NAME): $(OBJECT_FILES)
	$(call comp_exe)

$(LIBFT):
	$(call submodule_update_libft)

$(MLX42):
	$(call submodule_update_mlx42)

# bonus: $(SRCS_LIBFT_FILE) | $(OBJECT_FILES_BONUS)
# 	$(AR) $(NAME) $(OBJECT_FILES_BONUS)
# 	@echo "Compilação concluída: $(NAME)"

clean:
	$(call clean)
 
fclean: clean
	$(call fclean)
 
re: fclean all
 
.PHONY: all clean fclean re
.DEFAULT_GOAL := all
