/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:50:21 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/25 13:15:21 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_line	*alloc_data(char *file)
{
	int		cl;
	t_line	*data;

	cl = count_line_file(file);
	if (!(data = (t_line*)malloc(sizeof(t_line) * cl)))
		return (NULL);
	data[0].cl = cl;
	return (data);
}

t_line			*read_data(char *file)
{
	int			fd;
	t_line		*data;
	char		*line;
	int			cl;
	int			i;

	i = 0;
	data = alloc_data(file);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while ((cl = get_next_line(fd, &line)) > 0)
	{
		if ((!*line && !i) || cl == -1)
			return (NULL);
		if (!(data[i].line = ft_strsplit(line, ' ')))
			return (NULL);
		data[i].nb_point = ft_countwords(line, ' ');
		i++;
		free(line);
	}
	if ((!cl && !i) || (cl == -1))
		return (NULL);
	close(fd);
	return (data);
}

int				count_line_file(char *file)
{
	int			fd;
	char		*line;
	int			i;
	int			ret;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i++;
		free(line);
	}
	if (ret == -1)
		return (0);
	close(fd);
	return (i);
}

int				check_good_nbdata(t_line *data)
{
	int			nb_point;
	int			i;

	i = 0;
	if (data[0].cl != 32)
		return (0);
	nb_point = 32;
	while (i < data[0].cl)
	{
		if (nb_point != data[i].nb_point)
			return (0);
		i++;
	}
	return (1);
}
