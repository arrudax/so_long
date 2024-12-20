/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:19:09 by maanton2          #+#    #+#             */
/*   Updated: 2024/12/20 16:29:39 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
//	t_x x = (t_X) {0,0,{0,0}};

void	construct_map(char *path_map, t_map **map)
{
	int		fd;
	t_map	*p_map;

	fd = open(path_map, 'r');
	p_map = *map;
	*map->current_line = get_next_line(fd);
	while (*map->current_line != NULL)
	{
		*map->len_line = (int)strlen(*map->current_line);
		*map->next_line = NULL;
		p_map = p_map->next_line;
		*map->current_line = get_next_line(fd);
	}
}


t_render	*ft_render_map(char	*path_map)
{
	t_render	*render;
	t_map		*map;

	render = (t_render *)malloc(sizeof(t_render) * 1);
	if (!render)
		return (NULL);

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	while (map.next_line != NULL)
	{
		printf("%s", map.current_line);
		map.current_line = map.next_line;
	}
	construct_map(path_map, &map);
	return (render);
}
