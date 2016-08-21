/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testa_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:28:02 by avella            #+#    #+#             */
/*   Updated: 2016/02/03 16:32:06 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		testa(int x1, int y1, int x2, int y2)
{
	if ((x1 >= WIDTH) || (x2 >= WIDTH) || (y1 >= WIDTH) ||
		(y2 >= WIDTH) || (y1 <= 0) || (y2 <= 0) || (x1 <= 0) || (x2 <= 0))
		return (0);
	return (1);
}

int		color2(int val1, int val2, int color)
{
	if (val1 + val2 >= 30 && val1 + val2 <= 60)
		color = 0x167341;
	else if (val1 + val2 >= 61 && val1 + val2 <= 90)
		color = 0xDE5A39;
	else if (val1 + val2 >= 91 && val1 + val2 <= 130)
		color = 0x5D6ADC;
	else if (val1 + val2 >= 131 && val1 + val2 <= 200)
		color = 0xFF99CC;
	else if (val1 + val2 >= 201 && val1 + val2 <= 350)
		color = 0xDF571D;
	else
		color = 0xFFFFFF;
	return (color);
}

int		give_color(int val1, int val2)
{
	int color;

	color = 0;
	if (val1 + val2 < 0)
		color = 255 + (val1 + val2);
	else if (val1 + val2 >= 0 && val1 + val2 <= 3)
		color = 0xCCCC00;
	else if (val1 + val2 >= 4 && val1 + val2 <= 8)
		color = 0x4C9900;
	else if (val1 + val2 >= 9 && val1 + val2 <= 13)
		color = 0xFF8000;
	else if (val1 + val2 >= 14 && val1 + val2 <= 21)
		color = 0xFF6666;
	else if (val1 + val2 >= 22 && val1 + val2 <= 29)
		color = 0x6600CC;
	else
		color = color2(val1, val2, color);
	return (color);
}

void	first_part(char ***coord, int index, t_struct *param)
{
	t_temp *temp;

	temp = (t_temp *)malloc(sizeof(t_temp) * 12);
	temp->x1 = ft_atoi(coord[index][0]);
	temp->y1 = ft_atoi(coord[index][1]);
	temp->x2 = ft_atoi(coord[index + 1][0]);
	temp->y2 = ft_atoi(coord[index + 1][1]);
	temp->val1 = ft_atoi(coord[index][2]);
	temp->val2 = ft_atoi(coord[index + 1][2]);
	temp->color = give_color(temp->val1, temp->val2);
	if (testa(temp->x1, temp->y1, temp->x2, temp->y2))
		draw_line_on_img(param->img, temp, temp->color);
	free(temp);
}

void	second_part(char ***coord, int index, int maxline, t_struct *param)
{
	t_temp *temp;

	temp = (t_temp *)malloc(sizeof(t_temp) * 12);
	temp->x1 = ft_atoi(coord[index][0]);
	temp->y1 = ft_atoi(coord[index][1]);
	temp->x2 = ft_atoi(coord[index + maxline + 1][0]);
	temp->y2 = ft_atoi(coord[index + maxline + 1][1]);
	temp->val1 = ft_atoi(coord[index][2]);
	temp->val2 = ft_atoi(coord[index + maxline + 1][2]);
	temp->color = give_color(temp->val1, temp->val2);
	if (testa(temp->x1, temp->y1, temp->x2, temp->y2))
		draw_line_on_img(param->img, temp, temp->color);
	free(temp);
}
