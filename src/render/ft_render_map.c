/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:19:09 by maanton2          #+#    #+#             */
/*   Updated: 2025/01/06 17:03:22 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
//	t_x x = (t_X) {0,0,{0,0}};


int	ft_sup_r_c(int fd, char **map, t_render *render)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (render->len_line == 0)
			render->len_line = ft_strlen(line) - 1;
		if ( render->len_line > 0 && line[render->len_line] == '\n')
			line[render->len_line] = '\0';
		map[render->len_column] = ft_strdup(line);
		free(line);
		render->len_column++;
	}
	map[render->len_column++] = NULL;
	return (0);
}

void print_map(char **map)
{
    int i = 0;

    while (map[i] != NULL)
    {
			printf("%s", map[i]);
			i++;
		}
	}

	char	**ft_read_and_construct_map(char *path_map, t_render *render)
	{
		int		fd;
		char	**map;

		map = (char **)malloc(sizeof(char *) * 100);
		if (!map)
		{
			return (ft_putstr_fd("[ERRO] FAILED ON MEMORY\n", 2), NULL);
		}
		fd = open(path_map, O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			free(map);
			return (ft_putstr_fd("[ERRO] CANNOT OPEN THE MAP FILES\n", 2), NULL);
		}
		if (ft_sup_r_c(fd, map, render) == 1)
		{
			free(map);
			close(fd);
			return (ft_putstr_fd("[ERRO] THIS FILE IS EMPTY OR INVALID\n", 2), NULL);
		}
		close (fd);
		return (map);
	}

	t_sprite	*ft_load_textures(mlx_t *mlx)
	{
		int			i;
		char		*paths[10];
		t_sprite	*image;
		mlx_texture_t	*textures[10];

		i = 0;
		paths[0] = "./assets/floor_up_first.png";
		paths[1] = "./assets/floor_up_md.png";
		paths[2] = "./assets/floor_up_end.png";
		paths[3] = "./assets/floor_md_first.png";
		paths[4] = "./assets/floor_md_end.png";
		paths[5] = "./assets/floor_down_end.png";
		paths[6] = "./assets/floor_base_1.png";
		paths[7] = "./assets/floor_base_2.png";
		paths[8] = "./assets/floor_base_3.png";
		paths[9] = "./assets/floor_base_4.png";
		image = (t_sprite *)malloc(sizeof(t_sprite) * 1);
		if (!image)
			return (NULL);
		image->width = 64;
		image->height = 64;
		while (i < 10)
		{
			textures[i] = mlx_load_png(paths[i]);
			if (!textures[i])
				return (ft_putstr_fd("[ERR0R] UNABLE TO LOAD TEXTURES.\n", 2), NULL);
			image->sprite[i] = mlx_texture_to_image(mlx, textures[i]);
			mlx_delete_texture(textures[i]);
			if (!image->sprite[i])
				return (ft_putstr_fd("[ERR0R] UNABLE TO CREATE IMAGES.\n", 2), NULL);
			i++;
		}
		return (image);
	}

t_render	*ft_render(char *path_map, mlx_t *mlx)
{
	t_render	*render;

	render = (t_render *)malloc(sizeof(t_render) * 1);
	if (!render)
		return (NULL);
	render->assets = ft_load_textures(mlx);
	render->map = ft_read_and_construct_map(path_map, render);
	print_map(render->map);
	render->camera = NULL;
	return (render);
}

