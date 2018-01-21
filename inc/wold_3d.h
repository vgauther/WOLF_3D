/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wold_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:25:35 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/21 15:50:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# define HEI_WIN 720
# define LEN_WIN 1080
# define KEY_ESC 53
# define LEFT 0
# define RIGHT 2
# define FORWARD 13
# define BACKWARD 1

typedef struct	s_mlx_data
{
	void	*mlx;
	void	*win;
}				t_mlx_data;

typedef struct	s_img
{
	void	*img_ptr;
	char	*str;
}				t_img;

#endif
