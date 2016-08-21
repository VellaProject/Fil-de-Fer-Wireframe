/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:08:35 by avella            #+#    #+#             */
/*   Updated: 2016/02/15 18:51:02 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	*give_coorp(t_coor *coor, t_struct *param)
{
	coor->x = coor->xdep;
	coor->y = coor->ydep;
	coor->y += param->zoom;
	coor->xdep = coor->x;
	coor->ydep = coor->y;
	return (coor);
}

t_coor	*start_coorp(int x, int y)
{
	t_coor *coor;

	coor = (t_coor *)malloc(sizeof(t_coor) * 12);
	coor->v = 0;
	coor->j = 0;
	coor->x = x;
	coor->y = y;
	coor->xdep = x;
	coor->ydep = y;
	return (coor);
}

t_coor	*else_coorp(t_coor *coor, t_struct *param, int index)
{
	coor->x += param->zoom;
	if (param->coord[index][2][0] != '0')
	{
		coor->v = ft_atoi(param->coord[index][2]);
		coor->xtemp = coor->x + coor->v;
		coor->ytemp = coor->y - ((coor->v * 2) + 1);
		coor->j++;
	}
	return (coor);
}

char	***set_coordp(t_struct *param, float x, float y, int index)
{
	t_coor *coor;

	coor = start_coorp(x, y);
	while (index < param->i)
	{
		if (param->coord[index][2][0] == '\n')
			coor = give_coorp(coor, param);
		else
			else_coorp(coor, param, index);
		if (coor->j == 0)
		{
			param->coord[index][0] = ft_itoa(coor->x);
			param->coord[index][1] = ft_itoa(coor->y);
		}
		else
		{
			param->coord[index][0] = ft_itoa(coor->xtemp);
			param->coord[index][1] = ft_itoa(coor->ytemp);
			coor->j = 0;
		}
		index++;
	}
	free(coor);
	return (param->coord);
}
