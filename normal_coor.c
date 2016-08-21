/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:01:06 by avella            #+#    #+#             */
/*   Updated: 2016/02/15 18:50:46 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	*give_coor(t_coor *coor, t_struct *param)
{
	coor->x = coor->xdep;
	coor->y = coor->ydep;
	coor->x -= param->zoom * 0.86;
	coor->y += param->zoom * 0.5;
	coor->xdep = coor->x;
	coor->ydep = coor->y;
	return (coor);
}

t_coor	*start_coor(int x, int y)
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

t_coor	*else_coor(t_coor *coor, t_struct *param, int index)
{
	coor->x += param->zoom * 0.86;
	coor->y += param->zoom * 0.5;
	if (param->coord[index][2][0] != '0')
	{
		coor->v = ft_atoi(param->coord[index][2]);
		coor->xtemp = coor->x;
		coor->ytemp = coor->y - (coor->v * param->zoom);
		coor->j++;
	}
	return (coor);
}

char	***set_coordq(t_struct *param, float x, float y, int index)
{
	t_coor *coor;

	coor = start_coor(x, y);
	while (index < param->i)
	{
		if (param->coord[index][2][0] == '\n')
			coor = give_coor(coor, param);
		else
			else_coor(coor, param, index);
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
