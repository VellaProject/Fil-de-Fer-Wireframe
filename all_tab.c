/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:02:19 by avella            #+#    #+#             */
/*   Updated: 2016/02/16 14:39:55 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		run_try(char *txt)
{
	int i;

	i = 0;
	while (txt[i] != '\0')
	{
		if (txt[i] != ' ' && txt[i] != '\n' && txt[i] != '-')
		{
			if (!(txt[i] >= '0' && txt[i] <= '9'))
			{
				return (3);
			}
		}
		i++;
	}
	return (0);
}

void	err(void)
{
	ft_putstr("Bad file descriptor\n");
	exit(1);
}

char	**create_tab(char *argv)
{
	char	*line;
	char	*yt;
	int		fd;
	int		ret;
	char	**tab;

	fd = 0;
	ret = 0;
	fd = open(argv, O_RDONLY);
	line = (char *)malloc(sizeof(char) * 2);
	while ((ret = get_next_line(fd, &yt)) && ret != -1)
	{
		line = ft_strjoins(line, yt);
		line = ft_strjoins(line, " \n ");
		if (run_try(line) == 3)
			err();
	}
	if (ret == -1 || line[0] == '\0')
		err();
	tab = ft_strsplit(line, ' ');
	return (tab);
}

char	***create_coord_tab(char **tab, int i)
{
	int		index;
	char	***coord;

	index = 0;
	coord = (char ***)malloc(sizeof(char **) * i + 1);
	while (index < i)
	{
		coord[index] = (char **)malloc(sizeof(char *) * 5);
		index++;
	}
	index = 0;
	while (index < i)
	{
		coord[index][0] = (char *)malloc(sizeof(char) * 5);
		coord[index][1] = (char *)malloc(sizeof(char) * 5);
		coord[index][2] = tab[index];
		index++;
	}
	return (coord);
}
