/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:47:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/24 16:42:58 by vgauther         ###   ########.fr       */
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
	char	**tmp1;
	char	**tmp2;
	char	*str;
	int		len_tmp;
	int		i;

	i = 0;
	str = ft_open_n_read(target_name);
	tmp1 = ft_strsplit(str, '\n');
	map->len = ft_countwords(tmp1[0], ' ');
	while(tmp1[i])
		i++;
	if(!(map->map = malloc(sizeof(int *) * i)))
		malloc_error();
	map->hei = 0;
	while (map->map[map->hei])
	{
		if(!(map->map[map->hei] = malloc(sizeof(int) * map->len)))
			malloc_error();
		tmp2 = ft_strsplit(tmp1[map->hei], ' ');
		len_tmp = ft_countwords(tmp1[map->hei], ' ');
		if (len_tmp != map->len)
			map_error(1);
		len_tmp = 0;
		while(tmp2[len_tmp])
		{
			map->map[map->hei][len_tmp] = ft_atoi(tmp2[len_tmp]);
			len_tmp++;
		}
		map->hei++;
	}
}

t_bloc	**init_map(t_map map)
{
	int		x;
	int		y;
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
			b[y][x].len = 64;
			b[y][x].hei = 64;
			x++;
		}
		y++;
	}
	return (b);
}

void	init_player(t_player *p)
{
	p->cam.pos_x = LEN_WIN / 2;
	p->cam.pos_y = HEI_WIN / 2;
	p->hei = 64 / 2; // division d'une unite par deux
	p->angle_de_vue = 60; // 60 degres

}

int main(int argc, char **argv)
{
	t_mlx_data	mlx;
	t_map		map;
	int			i;
	t_bloc		**b;
	t_player	p;

	i = 0;
	if (argc == 1)
		usage();
	creat_map(argv[1], &map);
	b = init_map(map);
	init_player(&p);
	printf("%d\n",b[0][0].wall);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, LEN_WIN, HEI_WIN, "WOLF_3D");
	print_map(mlx);
	mlx_hook(mlx.win, 2, 0, hook, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
