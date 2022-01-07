/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:17:40 by exerath           #+#    #+#             */
/*   Updated: 2021/12/13 20:01:11 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_win	*init_win(int argc, char **argv)
{
	t_win		*win;

	win = (t_win *)malloc(sizeof(t_win));
	if (win == NULL)
		return (NULL);
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (NULL);
	win->mlx_win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "fractol");
	if (win->mlx_win == NULL)
		return (NULL);
	win->image = init_image(win->mlx);
	win->fractal = init_fractal(argc, argv);
	hooks(win);
	draw(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->image->img, 0, 0);
	instruction(win);
	mlx_loop(win->mlx);
	return (win);
}

t_image	*init_image(void *mlx)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (img == NULL)
		return (NULL);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
	if (img->addr == NULL)
		return (NULL);
	return (img);
}
