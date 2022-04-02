/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:27 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:33:10 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

float	get_vector_length(t_all *game, t_plr ray)
{
	float	delta_x;
	float	delta_y;

	delta_y = ray.y - game->player->y;
	delta_x = ray.x - game->player->x;
	return (sqrt(delta_x * delta_x + delta_y * delta_y));
}

t_plr	analize_ray(t_all *all, float deg)
{
	t_plr	ray1;
	t_plr	ray2;
	t_plr	ray;
	float	dv;
	float	dh;

	dv = vertical(all, deg, &ray1);
	dh = horizontal(all, deg, &ray2);
	if (dh < dv)
		ft_sn_wall(&ray, ray2, dh, deg);
	else
		ft_we_wall(&ray, ray1, dv, deg);
	ray.perp_length = ray.length
		* cos(ft_dg_to_rad(deg - all->player->dir));
	return (ray);
}

void	find_texture_x(t_all *all, t_plr *ray)
{
	if (ray->wall == SOUTH || ray->wall == NORTH)
	{
		ray->wall_x = ray->x / 64;
		ray->wall_x -= floor(ray->wall_x);
	}
	else
	{
		ray->wall_x = ray->y / 64;
		ray->wall_x -= floor(ray->wall_x);
	}
	all->map->texture[ray->wall].text_x = (int)
		(ray->wall_x * all->map->texture[ray->wall].width);
	if (ray->wall == EAST || ray->wall == SOUTH)
		all->map->texture[ray->wall].text_x = all->map->texture[ray->wall].width
			- all->map->texture[ray->wall].text_x - 1;
}

t_line	find_vertical_line(t_all *all, t_plr ray, int x_pos)
{
	t_line	line;
	double	column_height;

	column_height = WINDOW_HEIGHT * 64 / ray.perp_length;
	line.column_height = column_height;
	line.top = WINDOW_HEIGHT / 2 - column_height / 2;
	if (line.top < 0)
		line.top = 0;
	line.bot = WINDOW_HEIGHT / 2 + column_height / 2;
	if (line.bot > WINDOW_HEIGHT)
		line.bot = WINDOW_HEIGHT;
	line.x_pos = x_pos;
	return (line);
}

int	raycaster(t_all *all)
{
	float	deg;
	t_plr	ray;
	int		x_vert_line_pos;
	t_line	vert_line;

	deg = normal_deg(all->player->dir - 30);
	x_vert_line_pos = 0;
	while (x_vert_line_pos < WINDOW_WIDTH)
	{
		ray = analize_ray(all, deg);
		find_texture_x(all, &ray);
		vert_line = find_vertical_line(all, ray, x_vert_line_pos);
		ft_line(all, ray, vert_line);
		x_vert_line_pos++;
		deg += one_ray_angle(60, WINDOW_WIDTH);
		deg = normal_deg(deg);
	}
	return (1);
}
