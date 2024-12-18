/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:15 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/18 20:39:27 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	ft_create_window(void)
{
	mlx_t* mlx;
	
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Arrudax_so_long", false);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit (EXIT_FAILURE);
	}
	mlx_key_hook(mlx, (mlx_keyfunc)ft_hook, mlx);
	mlx_loop(mlx);
}
