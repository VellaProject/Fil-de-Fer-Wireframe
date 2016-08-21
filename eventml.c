/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventml.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:13:49 by avella            #+#    #+#             */
/*   Updated: 2016/02/03 16:13:53 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		event_mlx(int keycode, t_struct *param)
{
	if (keycode == 53)
		exit(1);
	img_move(keycode, param);
	img_zoom(keycode, param);
	img_other_view(keycode, param);
	img_other(keycode, param);
	return (0);
}
