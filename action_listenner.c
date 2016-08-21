/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_listenner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:49:05 by avella            #+#    #+#             */
/*   Updated: 2016/02/03 15:49:35 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_img(t_struct *prm, float xd, float yd)
{
	mlx_destroy_image(prm->mlx, prm->img->img_ptr);
	prm->img->img_ptr = mlx_new_image(prm->mlx, WIDTH, HEIGTH);
	set_coordq(prm, xd, yd, 0);
	draw_with_tab_on_img(prm->coord, prm->i, prm->maxline, prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img->img_ptr, 0, 0);
}

void	img_move(int keycode, t_struct *prm)
{
	if (keycode == 2)
	{
		prm->event->xd += 40;
		place_img(prm, prm->event->xd, prm->event->yd);
	}
	if (keycode == 1)
	{
		prm->event->yd += 40;
		place_img(prm, prm->event->xd, prm->event->yd);
	}
	if (keycode == 13)
	{
		prm->event->yd -= 40;
		place_img(prm, prm->event->xd, prm->event->yd);
	}
	if (keycode == 0)
	{
		prm->event->xd -= 40;
		place_img(prm, prm->event->xd, prm->event->yd);
	}
}

void	img_zoom(int keycode, t_struct *prm)
{
	if (keycode == 12)
	{
		if (prm->zoom < 5)
		{
			prm->zoom += 1;
		}
		else
			prm->zoom += 5;
		place_img(prm, prm->event->xd, prm->event->yd);
	}
	if (keycode == 14)
	{
		if (prm->zoom >= 10)
			prm->zoom -= 5;
		else
			prm->zoom -= 0.5;
		place_img(prm, prm->event->xd, prm->event->yd);
	}
}

void	img_other_view(int keycode, t_struct *prm)
{
	if (keycode == 124)
	{
		mlx_destroy_image(prm->mlx, prm->img->img_ptr);
		prm->img->img_ptr = mlx_new_image(prm->mlx, WIDTH, HEIGTH);
		set_coordp(prm, 10, 10, 0);
		draw_with_tab_on_img(prm->coord, prm->i, prm->maxline, prm);
		mlx_put_image_to_window(prm->mlx, prm->win, prm->img->img_ptr, 0, 0);
	}
	if (keycode == 123)
	{
		mlx_destroy_image(prm->mlx, prm->img->img_ptr);
		prm->img->img_ptr = mlx_new_image(prm->mlx, WIDTH, HEIGTH);
		set_coordp(prm, prm->event->xd, prm->event->yd, 0);
		draw_with_tab_on_img(prm->coord, prm->i, prm->maxline, prm);
		mlx_put_image_to_window(prm->mlx, prm->win, prm->img->img_ptr, 0, 0);
	}
}

void	img_other(int keycode, t_struct *prm)
{
	if (keycode == 17)
	{
		mlx_destroy_image(prm->mlx, prm->img->img_ptr);
		prm->img->img_ptr = mlx_new_image(prm->mlx, WIDTH, HEIGTH);
		set_coordx(prm, prm->event->xd, prm->event->yd, 0);
		draw_with_tab_on_img(prm->coord, prm->i, prm->maxline, prm);
		mlx_put_image_to_window(prm->mlx, prm->win, prm->img->img_ptr, 0, 0);
	}
	if (keycode == 36)
	{
		place_img(prm, prm->event->xd, prm->event->yd);
	}
}
