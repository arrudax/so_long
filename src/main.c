/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:02:38 by maanton2          #+#    #+#             */
/*   Updated: 2025/01/13 16:47:34 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "libft.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (ft_putstr_fd("Usage: ./so_long <map_file>\n", 2), 1);
    return (0);
}

