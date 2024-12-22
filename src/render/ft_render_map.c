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

int	ft_read_map_and_populeted_struct_list(t_list **map, char *path_map, size_t *c_l)
{
	int		fd;
	t_list	*node;
	t_list	*p_node;
	char	*line;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (1);
	}
	node = ft_lstnew(line);
	*map =  node;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			p_node = ft_lstnew(line);
			(*c_l) = ft_strlen(line);
			node->next = p_node;
			node = p_node;
		}
	}
	close(fd);
	return (0);
}

void	ft_draw_to_window(char *line)
{
	
}

int ft_check_map_filled(t_list *map)
{
	t_list *current_node;

	current_node = map;
	while (current_node != NULL)
	{
        printf("%s", (char *)current_node->content);
		ft_draw_to_window((char *)current_node->content);
        current_node = current_node->next;
    }
    return (0);
}

t_list	*ft_render_texture(char	*path_map, size_t *count_line, size_t *count_column)
{
	t_list		*map;

	if (ft_read_map_and_populeted_struct_list(&map, path_map, &count_line, &count_column) == 1)
		return (NULL);
	ft_check_map_filled(map, count);
	return (map);
}

t_render	*ft_render(char *path_map)
{
	t_render	*render;

	render = (t_render *)malloc(sizeof(t_render) * 1);
	if (!render)
		return (NULL);
	render->map = ft_render_texture(path_map, &render->line, &render->column);
	return (render);
}
