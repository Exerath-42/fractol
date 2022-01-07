/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 04:03:47 by exerath           #+#    #+#             */
/*   Updated: 2021/12/13 20:01:06 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	motion(int key, t_win *win)
{
	double	shift;

	shift = (win->fractal->re_max - win->fractal->re_min) * 0.1;
	if (key == KEY_UP)
	{
		win->fractal->im_max += shift;
		win->fractal->im_min += shift;
	}
	if (key == KEY_DOWN)
	{
		win->fractal->im_max -= shift;
		win->fractal->im_min -= shift;
	}
	if (key == KEY_RIGHT)
	{
		win->fractal->re_max += shift;
		win->fractal->re_min += shift;
	}
	if (key == KEY_LEFT)
	{
		win->fractal->re_max -= shift;
		win->fractal->re_min -= shift;
	}
}

int	zoom(int wheel, int x, int y, t_win *win)
{
	double	zoom;
	double	re;
	double	im;

	zoom = 1.0;
	if (wheel == SCROLL_UP || wheel == SCROLL_DOWN)
	{
		if (wheel == SCROLL_UP)
			zoom *= 1.5;
		else
			zoom *= 0.5;
		re = win->fractal->re_min + x * win->fractal->step_re;
		im = win->fractal->im_min + y * win->fractal->step_im;
		win->fractal->re_min = re + (win->fractal->re_min - re) * zoom;
		win->fractal->re_max = re + (win->fractal->re_max - re) * zoom;
		win->fractal->im_min = im + (win->fractal->im_min - im) * zoom;
		win->fractal->im_max = im + (win->fractal->im_max - im) * zoom;
		mlx_clear_window(win->mlx, win->mlx_win);
		draw(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->image->img, 0, 0);
		instruction(win);
	}
	return (0);
}
