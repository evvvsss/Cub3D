/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:53 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:34:02 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_sn_wall(t_plr *res, t_plr ray, float dist, float dg)
{
	res->x = ray.x;
	res->y = ray.y;
	if (ft_look_up(dg) == 1)
		res->wall = NORTH;
	else
		res->wall = SOUTH;
	res->length = dist;
}

void	ft_we_wall(t_plr *res, t_plr ray, float dist, float dg)
{
	res->x = ray.x;
	res->y = ray.y;
	if (ft_look_right(dg) == 1)
		res->wall = EAST;
	else
		res->wall = WEST;
	res->length = dist;
}

int	ft_check_wall(t_all *all, float side_dir)
{
	int	x;
	int	y;

	x = all->player->x;
	y = all->player->y;
	x += 64 * cos(ft_dg_to_rad(side_dir));
	y += 64 * sin(ft_dg_to_rad(side_dir));
	if ((all->map->my_map)[y / 64][x / 64] == '1')
		return (0);
	return (1);
}

void	ft_text_error(t_texture *text, char *path, t_all *all)
{
	text->img = mlx_xpm_file_to_image(all->win->mlx, path,
			&text->width, &text->height);
	if (!text->img)
		ft_error("Incorrect textures path ");
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
}

void	textures_init(t_all *all)
{
	all->map->texture = malloc(sizeof(t_texture) * NMBR_OF_TEXT);
	if (!all->map->texture)
		ft_error("Malloc failed\n");
	ft_text_error(&(all->map->texture[NORTH]), all->map->north, all);
	ft_text_error(&(all->map->texture[SOUTH]), all->map->south, all);
	ft_text_error(&(all->map->texture[WEST]), all->map->west, all);
	ft_text_error(&(all->map->texture[EAST]), all->map->east, all);
}
