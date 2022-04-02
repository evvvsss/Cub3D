/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:22 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:18:11 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_texture(t_all *all, t_plr ray, t_line line)
{
	int		color;
	float	text_y_step;
	float	text_pos;
	int		i;

	i = line.top;
	text_y_step = 1.0 * all->map->texture[ray.wall].height / line.column_height;
	text_pos = (i - WINDOW_HEIGHT / 2 + line.column_height / 2) * text_y_step;
	while (i < line.bot)
	{
		all->map->texture[ray.wall].text_y = (int)text_pos
			& (all->map->texture[ray.wall].height - 1);
		text_pos += text_y_step;
		color = get_texture_color(&all->map->texture[ray.wall],
				all->map->texture[ray.wall].text_x,
				all->map->texture[ray.wall].text_y);
		ft_mlx_pixel_put(all->win, line.x_pos, i, color);
		i++;
	}
}

void	ft_line(t_all *all, t_plr ray, t_line line)
{
	int	i;

	i = 0;
	while (i < line.top)
	{
		ft_mlx_pixel_put(all->win, line.x_pos, i, all->ceil_color);
		i++;
	}
	ft_texture(all, ray, line);
	i = line.bot;
	while (i < WINDOW_HEIGHT)
	{
		ft_mlx_pixel_put(all->win, line.x_pos, i, all->floor_color);
		i++;
	}
}
