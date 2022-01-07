/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:58:12 by exerath           #+#    #+#             */
/*   Updated: 2022/01/07 04:17:47 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (fractal == NULL)
		return (NULL);
	fractal->c.re = 0;
	fractal->c.im = 0;
	fractal->j.re = 0;
	fractal->j.im = 0;
	fractal->color = 0;
	fractal->im_max = 3;
	fractal->im_min = -3;
	fractal->re_max = 3;
	fractal->re_min = -3;
	fractal->step_re = (fractal->re_max - fractal->re_min) / WIDTH;
	fractal->step_im = (fractal->im_max - fractal->im_min) / HEIGHT;
	choose_fractal(fractal, argc, argv);
	fractal->iter = 100;
	return (fractal);
}

int	choose_fractal(t_fractal *fractal, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal->name_num = 1;
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc == 2)
		{
			fractal->j.re = -0.8228;
			fractal->j.im = -0.2087;
		}
		if (argc == 4)
		{
			fractal->j.re = atof(argv[2]);
			fractal->j.im = atof(argv[3]);
		}
		fractal->name_num = 2;
		return (2);
	}
	if (ft_strcmp(argv[1], "bfly") == 0)
		fractal->name_num = 3;
	return (0);
}

int	mandelbrot(t_fractal *fractal)
{
	t_complex	complex;
	int			iter_count;
	int			color;

	complex = init_complex(0, 0);
	iter_count = fractal->iter;
	color = fractal->color;
	while ((pow(complex.im, 2) + pow(complex.re, 2) <= 4) && iter_count > 0)
	{
		color += 0x00120000;
		complex = sum_complex(pow_complex(complex), init_complex(fractal->c.re, \
							fractal->c.im));
		iter_count--;
	}
	if (iter_count == 0)
		color = 0;
	return (color);
}

int	julia(t_fractal *fractal)
{
	t_complex	complex;
	t_complex	complex2;
	int			iter_count;
	int			color;

	complex = init_complex(fractal->c.re, fractal->c.im);
	complex2 = init_complex(pow(complex.re, 2), pow(complex.im, 2));
	iter_count = fractal->iter;
	color = fractal->color;
	while (pow(complex.re, 2) + pow(complex.im, 2) <= 4 && iter_count > 0)
	{
		color += 0x00001100;
		complex.im = 2 * complex.re * complex.im + fractal->j.im;
		complex.re = complex2.re - complex2.im + fractal->j.re;
		complex2.re = pow(complex.re, 2);
		complex2.im = pow(complex.im, 2);
		iter_count--;
	}
	if (iter_count == 0)
		color = 0xffccff;
	return (color);
}

int	bfly(t_fractal *fractal)
{
	t_complex	complex;
	int			iter_count;
	int			color;

	complex = init_complex(0, 0);
	iter_count = fractal->iter;
	color = fractal->color;
	while ((pow(complex.im, 2) + pow(complex.re, 2) <= 4) && iter_count > 0)
	{
		color += 0x0c0c11;
		complex = init_complex(fabs(pow(\
					complex.re, 2.0) - pow(complex.im, 2.0)) + fractal->c.re, \
					-2.0 * complex.re * complex.im + fractal->c.im);
		iter_count--;
	}
	if (iter_count == 0)
		color = 0;
	return (color);
}
