/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:42:22 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/20 16:29:39 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

# ifndef RENDER_H
# define RENDER_H

# include "MLX42/MLX42.h"
# include "window.h"
# include "libft.h"
# include "get_next_line.h"

# include <fcntl.h>

typedef struct s_position
{
	int	x;
	int	y;
} t_position;

typedef struct s_sprite
{
	mlx_texture_t	*sprite;
	int				width;
	int				height;
	struct s_sprite	*next;
} t_sprite;

typedef struct s_player
{
	t_sprite		*sprite;
	t_position		*position;
	int				speed;
} t_player;

typedef struct s_camera
{
	int				width;
	int				height;
	t_position		*position;
} t_camera;

typedef struct s_render
{
	t_list		*map;
	t_player	*player;
	t_camera	*camera;
	size_t			line;
	size_t			column;
} t_render;

t_render	*ft_render(char *path_map);

# define FLOOR '0'
# define WALL '1'
# define PLAYER 'P'
# define COLL 'C'
# define EXIT_DOOR 'E'

#endif
