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
	if (argc != 2)
		return (ft_putstr_fd("Usage: ./so_long <map_file>\n", 2), 1);
	if (!ft_check_extension(argv[1]))
		return (ft_putstr_fd("[ERR0R] map must have .ber extension!\n", 2), 1);
	ft_start_game(argv[1]);
    return (0);
}

