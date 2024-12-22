/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:15 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/20 09:32:15 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	ft_close_window(mlx_key_data_t key, t_game *game)
{
	printf("%d\n", key.key);
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
		return ;
	}
 
}
