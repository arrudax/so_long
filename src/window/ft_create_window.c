/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:15 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/20 09:32:34 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	ft_create_window(t_game *game)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Arrudax_so_long", false);
	if (!game->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit (EXIT_FAILURE);
	}
}
