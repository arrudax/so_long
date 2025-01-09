#ifndef CONTROLLER_H
#define CONTROLLER_H

# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_render t_render;

typedef struct s_game 
{
	mlx_t		*mlx;
	t_render	*render;
} t_game;

void	ft_start_game(const char *path_file);

#endif
