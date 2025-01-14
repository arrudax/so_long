/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:02:38 by maanton2          #+#    #+#             */
/*   Updated: 2025/01/14 15:56:56 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"

int32_t	ft_wirte_error(char *message)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int32_t	ft_valid_filename(char *filename)
{
	char	*p;

	p = filename;
	while (*p)
		p++;
	if (p == filename)
		return (ft_wirte_error("Empty filename"));
	p -= 4;
	if (p < filename || ft_strncmp(p, ".ber", 4) != 0)
		return (ft_wirte_error("Invalid extension, use .ber"));
	return (1);
}
