/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:42:22 by maanton2          #+#    #+#             */
/*   Updated: 2025/01/13 15:25:43 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WINDOW_H
# define WINDOW_H

# define WIDTH 1920
# define HEIGHT 995

# include <stdio.h>
# include <stdlib.h>
# include "MLX42/MLX42.h"

void	ft_create_window(t_game *game);
void	ft_close_window(mlx_key_data_t key, t_game *game);

#endif
