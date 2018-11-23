/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:31:28 by fde-souz          #+#    #+#             */
/*   Updated: 2018/02/26 17:17:26 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	map_error(int error)
{
	if (error == 0)
	{
		ft_putstr("\nSPAWN ERROR :");
		ft_putstr("\n - the spawn have to be surrounded by walkable area.");
		ft_putstr("\n - the spawn have to be unique in the map.");
		ft_putstr("\n - the number associated to the span is '3'.\n\n");
	}
	else if (error == 1)
		ft_putstr("\nMAP ERROR:\n - the map is not a 32x32 map\n\n");
	else if (error == 2)
		ft_putstr("\nMAP ERROR:\n - the border are not full of wall\n\n");
	else if (error == 4)
		ft_putstr("\nMAP ERROR:\n - ennemies are not on the good place\n\n");
	else if (error == 5)
		ft_putstr("\nMAP ERROR:\n - walls are not on the good place\n\n");
	else if (error == 6)
		ft_putstr("\nMAP ERROR:\n - spawn error\n\n");
	exit(0);
}

void	read_error(int error)
{
	if (error == 0)
		ft_putstr("\nOPEN ERROR:\n - the file is not valid file.\n\n");
	else if (error == 1)
		ft_putstr("\nREAD ERROR:\n - the file can't be read.\n\n");
	else if (error == 2)
		ft_putstr("\nTEXTURE ERROR:\n - a texture can't be load\n\n");
	else if (error == 3)
		ft_putstr("\nMALLOC ERROR: \n - a malloc failed\n\n");
	else if (error == 4)
		ft_putstr("\nTHREAD ERROR: \n - a thread failed\n\n");
	else if (error == 5)
		ft_putstr("\nusage: ./wolf3d map_file\n\n");
	exit(0);
}
