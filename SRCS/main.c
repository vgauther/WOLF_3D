/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:47:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/23 14:14:30 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf_3d.h"

int		hook(int keycode, void *param)
{
	(void)param;
	if(keycode == KEY_ESC)
		exit (0);
	return(0);
}

int		ft_close(t_mlx_data *mlx)
{
	(void)mlx;
	exit(EXIT_SUCCESS);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx_data mlx;

	if (argc == 1)
		usage();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1080, 720, "WOLD_3D");
	(void)argv;
	mlx_hook(mlx.win, 2, 0, hook, &mlx);
	mlx_hook(mlx.win, 17, 1L<< 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return 0;
}
