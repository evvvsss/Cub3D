/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:04 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:24:13 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	char_checker(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (CR_CHAR);
	else if (c == '1' || c == '0' || c == ' ')
		return (CR_SIGN);
	return (0);
}

static	int	help(char **map, int y, int x, int flag)
{
	if (!char_checker(map[y][x]))
		return (1);
	else if (char_checker(map[y][x]) == CR_CHAR && flag)
		return (1);
	else if (((map[y][x] != ' ' && map[y][x] != '1') && ((y != 0 &&
			(map[y - 1][x]) && map[y - 1][x] == ' ')
			|| (map[y + 1] && ((ft_strlen(map[y + 1]) <= x)
			|| map[y + 1][x] == ' '))
			|| (map[y][x - 1] && map[y][x - 1] == ' ')
			|| (!map[y][x + 1] || map[y][x + 1] == ' '))))
		return (1);
	return (0);
}

void	check(int flag)
{
	if (!flag)
		ft_error("Not valid map\n");
}

void	check_my_map(char **map)
{
	t_iter	it;

	ft_memset(&it, 0, sizeof(t_iter));
	while (map[it.x])
		it.x++;
	it.height = it.x - 1;
	while (map[it.y])
	{
		it.x = 0;
		while (map[it.y][it.x])
		{
			if (((map[it.y][it.x] != ' ' && map[it.y][it.x] != '1') &&
			((it.y == 0
			|| it.y == it.height) || (it.x == 0 || it.x == ft_strlen(map[it
			.y]) - 1))))
				ft_error("Not valid map\n");
			else if (help(map, it.y, it.x, it.start))
				ft_error("Not valid map\n");
			if (char_checker(map[it.y][it.x]) == CR_CHAR)
				it.start = 1;
			it.x++;
		}
		it.y++;
	}
	check(it.start);
}
