/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:03:06 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/24 13:34:56 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf_3d.h"

void	usage(void)
{
	ft_putstr("Usage : ./wold3d <map_name>\n");
	exit(0);
}

void	read_error(int num_err)
{
	if (num_err == 1)
		ft_putstr("READDING ERROR : the file does not exist.\n");
	else
		ft_putstr("READDING ERROR : wrong file.\n");
	exit(0);
}

void	map_error(int num_err)
{
	if (num_err == 1)
		ft_putstr("MAP ERROR : the map is not a rectangle.\n");
	exit(0);
}

void	malloc_error(void)
{
	ft_putstr("MALLOC ERROR : a malloc has failed.\n");
	exit(0);
}
