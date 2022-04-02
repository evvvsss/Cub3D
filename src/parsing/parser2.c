/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:16:59 by bferny            #+#    #+#             */
/*   Updated: 2022/03/26 20:15:48 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	map_checker(char *str, t_map *map)
{
	char	*new_str;
	int		fd;
	char	**map_str;

	ft_memset(map, 0, sizeof(t_map));
	map->ceil.r = NOTSET;
	map->floor.r = NOTSET;
	new_str = ft_strrchr(str, '.');
	if (!new_str || ft_strcmp(new_str, ".cub"))
		ft_error("Not correct format of the file\n");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Error");
	map_str = parsing(fd, str);
	if (!map_str)
		ft_error("Malloc failed\n");
	ft_map(map, map_str);
	free_map(map_str);
	check_my_map(map->my_map);
	map->width = ft_strlen(map->my_map[0]);
	while (map->my_map[map->height])
		map->height++;
	return (0);
}

char	**parsing(int file, char *file_name)
{
	int		rd;
	int		buf[8];
	int		size;
	char	*str;
	char	**str_split;

	size = 0;
	rd = 1;
	while (rd > 0)
	{
		rd = read(file, buf, 8);
		size += rd;
	}
	str = ft_calloc(size + 1, 1);
	close(file);
	file = open(file_name, O_RDONLY);
	rd = read(file, str, size);
	if (rd != size)
		ft_error("Read error");
	close(rd);
	str_split = ft_split(str, '\n');
	if (!str_split)
		ft_error("Malloc error\n");
	free(str);
	return (str_split);
}

void	ft_rgb(char *str, t_color *color)
{
	int		i;
	char	**help;

	if (color->r != NOTSET)
		ft_error("Not valid map\n");
	i = 2;
	while (str[i] == ' ')
		i++;
	help = ft_split(str + i, ',');
	if (!help)
		ft_error("Malloc failed\n");
	i = 0;
	while (help[i])
		i++;
	if (i != 3)
		ft_error("Not valid map\n");
	color->r = cust_atoi(help[0]);
	color->g = cust_atoi(help[1]);
	color->b = cust_atoi(help[2]);
	i = 2;
	while (i > -1)
		free(help[i--]);
	free(help);
}

void	ft_path(char *str, char **new)
{
	int	i;

	if (*new)
		ft_error("Not valid map\n");
	i = 2;
	while (str[i] == ' ')
		i++;
	*new = ft_substr(str, i, ft_strlen(str) - i);
	if (!(*new))
		ft_error("Malloc failed\n");
}

float	one_ray_angle(int fov, int width)
{
	return (fov * 1.0 / width);
}
