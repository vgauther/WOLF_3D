/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:47:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/24 13:56:11 by vgauther         ###   ########.fr       */
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

void	print_map(t_mlx_data mlx)
{
	int x;
	int y;

	x = 300;
	y = 300;
	while(y != 500)
	{
		while(x != 800)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, 255);
			x++;
		}
		x = 300;
		y++;
	}
}

void	creat_map(char *target_name, t_map *map)
{
	char	*str;
	int		len_tmp;

	str = ft_open_n_read(target_name);
	map->map = ft_strsplit(str, '\n');
	map->len = ft_countwords(map->map[0], ' ');
	map->hei = 0;
	while (map->map[map->hei])
	{
		len_tmp = ft_countwords(map->map[map->hei], ' ');
		if (len_tmp != map->len)
			map_error(1);
		map->hei++;
	}
}

t_bloc	**init_param(t_map map)
{
	int x;
	int y;
	t_bloc **b;

	y = 0;
	if(!(b = malloc(sizeof(t_bloc *) * map.hei)))
		malloc_error();
	while(y != map.hei)
	{
		if(!(b[y] = malloc(sizeof(t_bloc) * map.len)))
				malloc_error();
		x = 0;
		while(x != map.len)
		{
			b[y][x].wall = map.map[y][x];
			x++;
		}
		y++;
	}
	return (b);
}

int main(int argc, char **argv)
{
	t_mlx_data	mlx;
	t_map		map;
	int			i;
	t_bloc		**b;

	i = 0;
	if (argc == 1)
		usage();
	creat_map(argv[1], &map);
	b = init_param(map);
	printf("%d\n",b[0][0].wall);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1080, 720, "WOLF_3D");
	print_map(mlx);
	mlx_hook(mlx.win, 2, 0, hook, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
