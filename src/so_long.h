/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:54:01 by maanton2          #+#    #+#             */
/*   Updated: 2025/01/14 17:01:42 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft.h"

typedef enum s_asset_config 
{
	PLAYER = 0,
	COLLECTABLE,
	WALL,
	FLOOT,
	PORTAL,
} t_asset_config;

typedef struct s_chain
{
	size_t	size;
	char	**arr;
} t_chain;

typedef struct s_asset
{
	int32_t				y;
	int32_t				x;
	t_asset_config		asset_conf;
	t_chain				sprite;
} t_asset;

typedef struct s_map
{
	t_chain		line;
	t_asset		*player;
	t_asset		*portal;
} t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		map;
} t_game;

#endif
