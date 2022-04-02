/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrees.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:46 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:32:38 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

float	normal_deg(float dg)
{
	if (dg < 0)
		return (360 + dg);
	if (dg > 360)
		return (dg - 360);
	return (dg);
}

int	ft_look_up(float dg)
{
	if (dg > 180)
		return (1);
	else
		return (-1);
}

double	ft_dg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180));
}

int	ft_look_right(float dg)
{
	if (dg > 270 || dg < 90)
		return (1);
	else
		return (-1);
}

float	crossing(t_all *all, t_plr *ray, float distance)
{
	while (ray->map_x >= 0 && ray->map_y >= 0
		&& ray->map_x < all->map->width && ray->map_y < all->map->height)
	{
		if ((all->map->my_map)[ray->map_y][ray->map_x] == '1')
		{
			distance = get_vector_length(all, *ray);
			break ;
		}
		ray->y += ray->delta_y;
		ray->x += ray->delta_x;
		ray->map_x = ((int)(ray->x / 64));
		ray->map_y = ((int)(ray->y / 64));
	}
	return (distance);
}
