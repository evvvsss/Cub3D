/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:18:06 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:18:01 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	*free_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

int	close_hook(t_all *all)
{
	(void)all;
	exit (0);
}

void	rotate(int key, t_player *player)
{
	if (key == 2)
		player->dir = normal_deg(player->dir + 10);
	if (key == 0)
		player->dir = normal_deg(player->dir - 10);
}

int	key_hook(int keycode, t_all *all)
{
	double	side_dir;

	if (keycode == 53)
		exit(0);
	rotate(keycode, all->player);
	if (keycode == 1 || keycode == 13)
	{
		if (keycode == 1)
			side_dir = normal_deg(all->player->dir - 180);
		else if (keycode == 13)
			side_dir = all->player->dir;
		if (ft_check_wall(all, side_dir))
		{
			all->player->y += 8 * sin(ft_dg_to_rad(side_dir));
			all->player->x += 8 * cos(ft_dg_to_rad(side_dir));
		}
	}
	raycaster(all);
	mlx_put_image_to_window(all->win->mlx, all->win->mlx_win,
		all->win->img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map		map;
	t_win		win;
	t_player	player;
	t_all		all;
	t_plr		plr;

	errno = 0;
	if (argc != 2)
		ft_error("Not correct number of arguments\n");
	map_checker(argv[1], &map);
	all.map = &map;
	find_unit(&player, all.map->my_map);
	all.plr = &plr;
	all.player = &player;
	win.mlx = mlx_init();
	all.floor_color = ft_rgb_to_int(map.floor.r, map.floor.g, map.floor.b);
	all.ceil_color = ft_rgb_to_int(map.ceil.r, map.ceil.g, map.ceil.b);
	all.win = &win;
	textures_init(&all);
	all.win->mlx_win = mlx_new_window(all.win->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Cub3D");
	main_add(all);
	return (0);
}
