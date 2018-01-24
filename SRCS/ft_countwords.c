/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:53:39 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 16:55:30 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countwords(char const *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i])
				word++;
			while (s[i] != c && s[i])
				i++;
		}
		return (word);
	}
	return (0);
}
