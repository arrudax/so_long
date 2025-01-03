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

int	ft_read_map_to_list(t_list **map, char *path_map, size_t *l_l, size_t *l_c)
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
	(*l_l) = ft_strlen(line) - 1;
	(*l_c)++;
	*map =  node;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			(*l_c)++;
			p_node = ft_lstnew(line);
			node->next = p_node;
			node = p_node;
		}
	}
	free(line);
	close(fd);
	return (0);
}

int ft_print_map(t_list *map)
{
	t_list *current_node;

	current_node = map;
	while (current_node != NULL)
	{
        printf("%s", (char *)current_node->content);
        current_node = current_node->next;
    }
    return (0);
}

t_sprite	*ft_load_textures(void)
{
	int			i;
	int			j;
	char		paths[4][4];
	t_sprite	*textures;
	mlx_texture_t	**sprite;

	i = 0;
	textures = (t_sprite *)malloc(sizeof(t_sprite) * 1);
	if (!textures)
		return (NULL);
	paths[0][0] = "./assets/floor_up_first.png";
	paths[0][1] = "./assets/floor_up_md.png";
	paths[0][2] = "./assets/floor_up_end.png";
	paths[1][0] = "./assets/floor_md_first.png";
	paths[1][1] = "./assets/floor_md_end.png";
	paths[2][0] = "./assets/floor_down_end.png";
	paths[3][0] = "./assets/floor_base_1.png";
	paths[3][1] = "./assets/floor_base_2.png";
	paths[3][2] = "./assets/floor_base_3.png";
	paths[3][3] = "./assets/floor_base_4.png";
	textures->width = 64;
	textures->height = 64;
	sprite = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * 4);
	if (!sprite)
		return (NULL);
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (paths[i][j] != NULL)
			{
				sprite[i][j] = mlx_load_png(paths[i][j]);
				if (!sprite[i][j])
					return (ft_putstr_fd("[ERR0R] UNABLE TO LOAD TEXTURES.\n", 2), 0);
				textures->sprite = mlx_texture_to_image(mlx, sprite[i][j]);
				mlx_delete_texture(sprite[i][j]);
				if (!textures->sprite[i][j])
					return (ft_putstr_fd("[ERR0R] UNABLE TO CREATE IMAGES.\n", 2), 0);
			}
			j++;
		}
		i++;
	}
	return (textures);
}

int	ft_render_img_window(mlx_t *mlx, t_list *map, size_t l_l, size_t l_c)
{
	t_list	*node;

	node = map;
	while (node != NULL)
	{
		
		node = node->next;
	}
}

t_list	*ft_load_map(mlx_t *mlx, char *path_map, t_render *render)
{
	t_list		*map;

	if (ft_read_map_to_list(&map, path_map, &render->len_line, &render->len_column) == 1)
		return (NULL);
	ft_print_map(map); //print gnl readed
	ft_render_map(mlx, map, &render->len_line, &render->len_column);
	return (map);
}

t_render	*ft_render(char *path_map, mlx_t *mlx)
{
	t_render	*render;

	render = (t_render *)malloc(sizeof(t_render) * 1);
	if (!render)
		return (NULL);
	render->assets = ft_load_textures();
	render->map = ft_load_map(mlx, path_map, render);
	return (render);
}
