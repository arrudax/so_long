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

int	ft_read_map_to_list(char **map, char *path_map, size_t *l_l, size_t *l_c)
{
	int		fd;
	char	**line;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (1);
	}
	(*l_l) = ft_strlen(line) - 1;
	(*l_c)++;

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

t_sprite	*ft_load_textures(mlx_t *mlx)
{
	int				i;
	t_sprite		*image;
	char			*paths[9];
	mlx_texture_t	*textures[9];


	image = (t_sprite *)malloc(sizeof(t_sprite));
	if (!image)
		 return (NULL);
	i = 0;
	paths[0] = "./assets/floor/floor.png";
	paths[1] = "./assets/floor/floor_up_first.png";
	paths[2] = "./assets/floor/floor_up_middle.png";
	paths[3] = "./assets/floor/floor_up_end.png";
	paths[4] = "./assets/floor/floor_md_first.png";
	paths[5] = "./assets/floor/floor_md_end.png";
	paths[6] = "./assets/floor/floor_down_first.png";
	paths[7] = "./assets/floor/floor_down_middle.png";
	paths[8] = "./assets/floor/floor_down_end.png";
	image->width = 64;
	image->height = 64;
	while (i < 9)
	{
		textures[i] = mlx_load_png(paths[i]);
		if (!textures[i])
		{
			free(image);
			return (ft_putstr_fd("[ERR0R] UNABLE TO LOAD TEXTURES.\n", 2), NULL);
		}
		image->sprite[i] = mlx_texture_to_image(mlx, textures[i]);
		mlx_delete_texture(textures[i]);
		if (!image->sprite[i])
		{
			free(image);
			return (ft_putstr_fd("[ERR0R] UNABLE TO CREATE IMAGES.\n", 2), NULL);
		}
		i++;
	}
	return (image);
}

int	ft_render_img_window(mlx_t *mlx, t_list *map, t_render *render)
{
	size_t		l_l;
	t_list	*node;

	node = map;
	while (node != NULL)
	{
		l_l = 0;
		while (l_l < render->len_line)
		{
			if (((char *)node->content)[l_l] == '1')
				mlx_image_to_window(mlx, render->assets->sprite[0], l_l * 64, l_l * 64);
			l_l++;
		}
		node = node->next;
	}
	return (1);
}

t_list	*ft_load_map(mlx_t *mlx, char *path_map, t_render *render)
{
	t_list		*map;

	(void)mlx;
	if (ft_read_map_to_list(&map, path_map, &render->len_line, &render->len_column) == 1)
		return (NULL);
	ft_print_map(map); //print gnl readed
	ft_render_img_window(mlx, map, render);
	return (map);
}

t_render	*ft_render(char *path_map, mlx_t *mlx)
{
	t_render	*render;

	render = (t_render *)malloc(sizeof(t_render) * 1);
	if (!render)
		return (NULL);
	render->assets = ft_load_textures(mlx);
	render->map = ft_load_map(mlx, path_map, render);
	return (render);
}
