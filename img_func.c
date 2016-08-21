/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:18:33 by avella            #+#    #+#             */
/*   Updated: 2016/02/03 16:44:51 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		new_index(int index, int futurindex)
{
	if (futurindex > 0)
	{
		index += 2;
		futurindex = 0;
	}
	else
		index++;
	return (index);
}

int		new_futurindex(int index, int futurindex)
{
	if (futurindex > 0)
	{
		index += 2;
		futurindex = 0;
	}
	else
		index++;
	return (futurindex);
}

void	draw_with_tab_on_img(char ***coord, int i, int maxline, t_struct *param)
{
	int index;
	int futurindex;

	futurindex = 0;
	index = 0;
	while (index + 1 < i)
	{
		if (index + 1 < i)
		{
			if (coord[index + 1][2][0] != '\n')
				first_part(coord, index, param);
			else
				futurindex++;
		}
		if (index + maxline + 1 < i)
		{
			if (coord[index + maxline + 1][2][0] != '\n')
				second_part(coord, index, maxline, param);
			else
				futurindex++;
		}
		index = new_index(index, futurindex);
		futurindex = new_futurindex(index, futurindex);
	}
}

void	my_pixel_put_to_image(t_img *myimg, int x, int y, int color)
{
	myimg->data = mlx_get_data_addr(myimg->img_ptr,
					&myimg->bpp, &myimg->sizeline, &myimg->endian);
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8] = color % 256;
	color /= 256;
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8 + 1] = color % 256;
	color /= 256;
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8 + 2] = color % 256;
}
