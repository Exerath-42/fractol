/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:57:59 by exerath           #+#    #+#             */
/*   Updated: 2021/12/13 20:00:02 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	pixel_color(t_fractal *fractal)
{
	if (fractal->name_num == 1)
		return (mandelbrot(fractal));
	if (fractal->name_num == 2)
		return (julia(fractal));
	if (fractal->name_num == 3)
		return (bfly(fractal));
	else
		finish(0);
	return (0);
}

void	draw(t_win *win)
{
	t_fractal	*tmp;
	int			x;
	int			y;
	int			color;

	y = 0;
	tmp = win->fractal;
	tmp->step_re = (tmp->re_max - tmp->re_min) / WIDTH;
	tmp->step_im = (tmp->im_max - tmp->im_min) / HEIGHT;
	while (y < HEIGHT)
	{
		tmp->c.im = tmp->im_min + y * tmp->step_im;
		x = 0;
		while (x < WIDTH)
		{
			tmp->c.re = tmp->re_min + x * tmp->step_re;
			color = pixel_color(tmp);
			my_mlx_pixel_put(win->image, x, y, color);
			x++;
		}
		y++;
	}
}
