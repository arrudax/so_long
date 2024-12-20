/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:19:09 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/20 14:35:12 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
//	t_x x = (t_X) {0,0,{0,0}};

t_map	*construct_map(char *path_map)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	while (get)
	return (map);
}


t_render	*ft_render_map(char	*path_map)
{
	t_render	*render;

	render = (t_render *)malloc(sizeof(t_render) * 1);
	if (!render)
		return (NULL);
	render->map = construct_map(path_map);
	printf("%s", path_map);
	return (render);
}
