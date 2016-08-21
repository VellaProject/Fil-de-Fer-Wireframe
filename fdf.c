/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:04:49 by avella            #+#    #+#             */
/*   Updated: 2016/02/03 16:17:30 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int			i;
	t_struct	*mystruct;
	char		***coord;
	char		**tab;

	i = 0;
	if (error(argc) == 0)
		return (0);
	mystruct = give();
	legend(mystruct->mlx, mystruct->win);
	tab = create_tab(argv[1]);
	while (tab[i])
		i++;
	coord = create_coord_tab(tab, i);
	mystruct = give2(mystruct, i, tab, coord);
	mystruct->img = give_img(mystruct->mlx);
	mystruct->event = give_myevent();
	mlx_key_hook(mystruct->win, event_mlx, mystruct);
	mlx_loop(mystruct->mlx);
	return (0);
}
