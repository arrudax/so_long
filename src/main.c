/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:02:38 by maanton2          #+#    #+#             */
/*   Updated: 2025/01/06 17:06:50 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_write_map_to_window(mlx_t *mlx, t_render *render)
	{
		size_t	line;
		size_t col;

		col = 0;
		line = 0;
		printf("\n%zu", line);
		printf("\n%zu", col);
		printf("\n%zu", render->len_line);
		printf("\n%zu", render->len_column);
		(void)mlx;
		while (col < render->len_column)
		{
			line = 0;
			while (line < render->len_line)
			{
				mlx_image_to_window(mlx, render->assets->sprite[0], line * render->assets->width, col * render->assets->height);
				if (render->map[col][line] == '1')
					mlx_image_to_window(mlx, render->assets->sprite[0], line * render->assets->width, col * render->assets->height);
				else if (render->map[col][line] == 'C')
					mlx_image_to_window(mlx, render->assets->sprite[0], line * render->assets->width, col * render->assets->height);
				else if (render->map[col][line] == 'E')
					mlx_image_to_window(mlx, render->assets->sprite[0], line * render->assets->width, col * render->assets->height);
				else if (render->map[col][line] == 'P')
					mlx_image_to_window(mlx, render->assets->sprite[0], line * render->assets->width, col * render->assets->height);
				line++;
			}
			col++;
		}
}
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (1);
	game.mlx = NULL;
	ft_create_window(&game); // retornar mlx
	game.render = ft_render(argv[1], game.mlx);
	ft_write_map_to_window(game.mlx, game.render);
	mlx_key_hook(game.mlx, (mlx_keyfunc)ft_close_window, &game);
	mlx_loop(game.mlx);
    return (0);
}

