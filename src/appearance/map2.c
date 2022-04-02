/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:33 by bferny            #+#    #+#             */
/*   Updated: 2022/03/25 17:18:51 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

float	vertical(t_all *game, double dg, t_plr *ray)
{
	float	distance;

	distance = MAXFLOAT;
	if (ft_look_right(dg) == 1)
		ray->delta_x = 64;
	else
		ray->delta_x = -64;
	if (dg == 90 || dg == 270)
		return (distance);
	if (ft_look_right(dg) == 1)
		ray->x = (int)((game->player->x / 64) * 64) + 64;
	else
		ray->x = (int)((game->player->x / 64) * 64) + (-0.001);
	ray->y = game->player->y + (game->player->x - ray->x)
		* tan(ft_dg_to_rad(dg)) * (-1);
	ray->delta_y = ray->delta_x * tan(ft_dg_to_rad(dg));
	ray->map_x = ((int)(ray->x / 64));
	ray->map_y = ((int)(ray->y / 64));
	distance = crossing(game, ray, distance);
	return (distance);
}

float	horizontal(t_all *game, double dg, t_plr *ray)
{
	float	distance;

	distance = MAXFLOAT;
	if (ft_look_up(dg) == 1)
		ray->delta_y = -1 * SIZE;
	else
		ray->delta_y = 1 * SIZE;
	if (dg == 0 || dg == 180 || dg == 360)
		return (distance);
	if (ft_look_up(dg) == 1)
		ray->y = (int)((game->player->y / 64) * 64) + (-0.001);
	else
		ray->y = (int)((game->player->y / 64) * 64) + 64;
	ray->x = game->player->x + (game->player->y - ray->y)
		/ tan(ft_dg_to_rad(dg)) * (-1);
	ray->delta_x = ray->delta_y / tan(ft_dg_to_rad(dg));
	ray->map_x = ((int)(ray->x / 64));
	ray->map_y = ((int)(ray->y / 64));
	distance = crossing(game, ray, distance);
	return (distance);
}
