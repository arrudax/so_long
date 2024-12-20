/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:02:38 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/18 19:59:29 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t main(void)
{
	t_game	game;

	game.mlx = NULL;
	game.window = NULL;
	printf("%zu", ft_strlen("hello"));
	ft_create_window(game.mlx);
    return (0);
}

