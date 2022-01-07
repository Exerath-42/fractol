/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:58:20 by exerath           #+#    #+#             */
/*   Updated: 2022/01/07 02:55:28 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	closer(int key)
{
	if (key == ESC)
	{
		finish(1);
	}
	return (key);
}

void	instruction(t_win *win)
{
	mlx_string_put(win->mlx, win->mlx_win, 10, 20, 0xFFFF33, "iter");
	mlx_string_put(win->mlx, win->mlx_win, 80, 20, 0x483d8b, "button[i]");
	mlx_string_put(win->mlx, win->mlx_win, 180, 20, 0x8b008b, \
	ft_itoa(win->fractal->iter));
	mlx_string_put(win->mlx, win->mlx_win, 10, 190, 0xFFFF33, "zoom");
	mlx_string_put(win->mlx, win->mlx_win, 80, 180, 0x483d8b, "scrool UP");
	mlx_string_put(win->mlx, win->mlx_win, 80, 200, 0x483d8b, "scrool DOWN");
	mlx_string_put(win->mlx, win->mlx_win, 10, 130, 0xFFFF33, "move");
	mlx_string_put(win->mlx, win->mlx_win, 80, 130, 0x483d8b, "LEFT  |");
	mlx_string_put(win->mlx, win->mlx_win, 125, 110, 0x483d8b, " UP");
	mlx_string_put(win->mlx, win->mlx_win, 160, 130, 0x483d8b, "RIGHT");
	mlx_string_put(win->mlx, win->mlx_win, 120, 150, 0x483d8b, "DOWN");
	mlx_string_put(win->mlx, win->mlx_win, 10, 80, 0xFFFF33, "color");
	mlx_string_put(win->mlx, win->mlx_win, 80, 80, 0x483d8b, "button[c]");
	mlx_string_put(win->mlx, win->mlx_win, 10, 50, 0xFFFF33, "exit");
	mlx_string_put(win->mlx, win->mlx_win, 80, 50, 0x483d8b, "button[esc]");
}

int	key_cheker(int key, t_win *win)
{
	if (key == ESC)
		closer(key);
	else if (key == KEY_UP || key == KEY_DOWN || \
		key == KEY_LEFT || key == KEY_RIGHT)
		motion(key, win);
	else if (key == C_KEY)
		win->fractal->color += 0x001109;
	else if (key == I_KEY)
	{
		if (win->fractal->iter < 1000)
			win->fractal->iter += 100;
	}
	else if (key == D_KEY)
		win->fractal->iter = 100;
	mlx_clear_window(win->mlx, win->mlx_win);
	draw(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->image->img, 0, 0);
	instruction(win);
	return (key);
}

int	closer2(void)
{
	finish(1);
	return (0);
}

void	hooks(t_win *win)
{
	mlx_hook(win->mlx_win, 17, 0, closer2, win);
	mlx_hook(win->mlx_win, 2, 0, key_cheker, win);
	mlx_hook(win->mlx_win, WHEEL, 0, zoom, win);
}
