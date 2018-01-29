/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:28:26 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/25 13:53:35 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf_3d.h"

void	put_pixel_image(t_pixel pixel, t_mlx_data mlx, t_img *img, int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	(void)mlx;
	pixel.color = color;
	r = (pixel.color >> 16) & 0xff;
	g = (pixel.color >> 8) & 0xff;
	b = pixel.color & 0xff;
	img->str[(pixel.x * 4) + (img->len * 4 * pixel.y)] = b;
	img->str[(pixel.x * 4) + (img->len * 4 * pixel.y) + 1] = g;
	img->str[(pixel.x * 4) + (img->len * 4 * pixel.y) + 2] = r;
	img->str[(pixel.x * 4) + (img->len * 4 * pixel.y) + 3] = 0;
}
