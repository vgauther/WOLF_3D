/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:59:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/27 12:46:59 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf_3d.h"

void	mini_map(t_bloc **b, t_map map, t_mlx_data mlx)
{
	t_img		mini_map;
	t_pixel		p;
	int			tmp;
	int			tmp2;
	int			color;
	int			x;
	int			y;
	int			tmp_;
	int			tmp_2;

	x = 0;
	y = 0;
	mini_map.len = 5 * 2 * 3 * 5;
	mini_map.hei = 5 * 2 * 3 * 5;
	tmp_ = mini_map.len / map.len;
	tmp_2 = mini_map.hei / map.hei;
	mini_map.img_ptr = mlx_new_image(mlx.mlx, mini_map.len, mini_map.hei);
	mini_map.str = mlx_get_data_addr(mini_map.img_ptr, &mini_map.bits, &mini_map.size_line, &mini_map.endian);
	p.y = 0;
	color = 255;
	tmp2 = 0;
	while(p.y != mini_map.hei)
	{
		p.x = 0;
		tmp = 0;
		color = 255;
		while(p.x != mini_map.len)
		{
		//	printf("test\n");
			if(b[y][x].wall == 1)
				color = 255;
			else
				color = 0xFF0000;
			if(tmp == tmp_)
			{
		//	printf("%d\n",tmp);
				tmp = 0;
			//	printf("%d\n", x);
				x++;
			}
			put_pixel_image(p, mlx, &mini_map, color);
			p.x++;
			tmp++;
		}
		if(tmp2 == tmp_2)
		{
			printf("%d\n", y);
			tmp2 = 0;
			y++;
		}
		x = 0;
		tmp2++;
		p.y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mini_map.img_ptr , 30, 30);
}
