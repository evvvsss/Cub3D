/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:24:15 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:18:00 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	main_add(t_all all)
{
	all.win->img = mlx_new_image(all.win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	all.win->addr = mlx_get_data_addr(all.win->img,
			&all.win->bpp, &all.win->line_l, &all.win->en);
	raycaster(&all);
	mlx_put_image_to_window(all.win->mlx, all.win->mlx_win, all.win->img, 0, 0);
	mlx_hook(all.win->mlx_win, 17, 0, close_hook, &all);
	mlx_hook(all.win->mlx_win, 2, (1L << 0), &key_hook, &all);
	mlx_loop(all.win->mlx);
}
