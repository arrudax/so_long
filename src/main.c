/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:02:38 by maanton2          #+#    #+#             */
/*   Updated: 2025/01/14 16:28:21 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (ft_wirte_error("use .ber files"), 1);
	if (ft_valid_filename(argv[1]))
			return (1);
	return (0);
}
