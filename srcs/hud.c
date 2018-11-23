/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:11:17 by fde-souz          #+#    #+#             */
/*   Updated: 2018/02/16 11:13:23 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cursor(t_win_info *w)
{
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 + 3, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 + 4, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 + 5, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 + 6, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 - 3, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 - 4, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 - 5, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2, SIZE_Y / 2 - 6, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 - 3, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 - 4, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 - 5, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 - 6, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 + 3, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 + 4, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 + 5, SIZE_Y / 2, 0xFFFFFF, w);
	put_pixel_image(SIZE_X / 2 + 6, SIZE_Y / 2, 0xFFFFFF, w);
}

void	rectangle(t_rectangle r, t_win_info *w)
{
	int x;
	int y;

	y = 0;
	while (y != r.hei)
	{
		x = 0;
		while (x != r.len)
		{
			put_pixel_image(r.x + x, r.y + y, r.color, w);
			x++;
		}
		y++;
	}
}

void	life_point(t_win_info *w)
{
	t_rectangle r;

	r.x = (SIZE_X / 2) + (SIZE_X / 4) + (SIZE_X / 16);
	r.y = 15;
	r.len = w->player.life;
	r.hei = 10;
	r.color = 0x00FF00;
	rectangle(r, w);
}

void	hud(t_win_info *w)
{
	life_point(w);
	cursor(w);
	minimap(w);
}

void	image_hud(t_win_info *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->k, 42, 443);
	mlx_put_image_to_window(w->mlx, w->win, w->h,
		(SIZE_X / 2) + (SIZE_X / 4) + (SIZE_X / 16) - 25, 13);
	ammo(w);
}
