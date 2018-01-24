/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_n_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:40:21 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/23 15:48:40 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf_3d.h"

char	*ft_read(int fd)
{
	char	*str;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	if (ret == -1)
		read_error(42);
	return (str);
}

char	*ft_open_n_read(char *target)
{
	int		fd;
	char	*str_ret;

	if ((fd = open(target, O_RDONLY)) < 0)
		read_error(1);
	str_ret = ft_read(fd);
	return (str_ret);
}
