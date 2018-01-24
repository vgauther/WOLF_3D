/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:25:35 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/24 13:35:31 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# define BUFF_SIZE 4096
# define HEI_WIN 720
# define LEN_WIN 1080
# define KEY_ESC 53
# define LEFT 0
# define RIGHT 2
# define FORWARD 13
# define BACKWARD 1

#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** structures
*/

typedef struct	s_bloc
{
	int		hei;
	int		len;
	int		wall;
}				t_bloc;

typedef struct	s_player
{
	int		hei;
	int		angle_de_vue;
}				t_player;

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

typedef struct	s_map
{
	char	**map;
	int		len;
	int		hei;
}				t_map;

/*
** error.c
*/

void	usage(void);
void	read_error(int num_err);
void	map_error(int num_err);
void	malloc_error(void);

/*
** ft_open_n_read.c
*/

char	*ft_open_n_read(char *target);

/*
** ft_countwords.c
*/

int	ft_countwords(char const *s, char c);


#endif
