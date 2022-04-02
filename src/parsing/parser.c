/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:11 by bferny            #+#    #+#             */
/*   Updated: 2022/03/25 17:21:22 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	map_to_char_help(char **old_map, t_iter iter, char ***new_map, char *
help)
{
	while (old_map[iter.start])
	{
		(*new_map)[iter.y] = ft_substr(help, 0, iter.border);
		if (!(*new_map)[iter.y])
			ft_error("Malloc failed");
		(*new_map)[iter.y] = ft_memcpy((*new_map)[iter.y],
				old_map[iter.start], ft_strlen(old_map[iter.start]));
		iter.y++;
		iter.start++;
	}
}

void	map_to_char(int i, char **old_map, char **new_map[])
{
	t_iter	iter;
	char	*help;

	ft_memset(&iter, 0, sizeof(t_iter));
	while (old_map[i] && old_map[i][0] == '\n')
		i++;
	iter.start = i;
	if (!old_map[i])
		ft_error("Not Valid map");
	while (old_map[i])
	{
		if (ft_strlen(old_map[i]) > iter.border)
			iter.border = ft_strlen(old_map[i]);
		i++;
	}
	(*new_map) = ft_calloc(sizeof(char *), i - iter.start + 1);
	help = ft_calloc(sizeof(char), iter.border + 1);
	if (!(*new_map) || !help)
		ft_error("Malloc failed\n");
	help = ft_memset(help, ' ', iter.border);
	map_to_char_help(old_map, iter, new_map, help);
	free(help);
}

void	ft_map(t_map *map, char **map_str)
{
	int	i;

	i = 0;
	while (map_str[i])
	{
		if (!ft_strncmp(map_str[i], "NO ", 3))
			ft_path(map_str[i], &(map->north));
		else if (!ft_strncmp(map_str[i], "SO ", 3))
			ft_path(map_str[i], &(map->south));
		else if (!ft_strncmp(map_str[i], "WE ", 3))
			ft_path(map_str[i], &(map->west));
		else if (!ft_strncmp(map_str[i], "EA ", 3))
			ft_path(map_str[i], &(map->east));
		else if (!ft_strncmp(map_str[i], "F ", 2))
			ft_rgb(map_str[i], &(map->floor));
		else if (!ft_strncmp(map_str[i], "C ", 2))
			ft_rgb(map_str[i], &(map->ceil));
		else if ((!(map->north) || !(map->south) || !(map->east) || !(map->west)
				|| map->floor.r == NOTSET || map->ceil.r == NOTSET)
			&& map_str[i] && map_str[i][0] != '\n')
			ft_error("Not valid map\n");
		else
			return (map_to_char(i, map_str, &map->my_map));
		i++;
	}
}
