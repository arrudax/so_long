/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:02:38 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/20 14:05:19 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (1);
	game.mlx = NULL;
	game.render = ft_render_map(argv[1]);
	ft_create_window(&game);
	mlx_key_hook(game.mlx, (mlx_keyfunc)ft_close_window, &game);
	mlx_loop(game.mlx);
    return (0);
}

