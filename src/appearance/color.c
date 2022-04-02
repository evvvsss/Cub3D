/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:17:39 by bferny            #+#    #+#             */
/*   Updated: 2022/03/25 17:16:05 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	void	*dst;

	dst = win->addr + (y * win->line_l + x * (win->bpp / 8));
	*(int *)dst = color;
}

int	get_texture_color(t_texture *texture, int x, int y)
{
	void	*dst;

	dst = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(int *)dst);
}

int	ft_rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}
