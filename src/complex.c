/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:57:56 by exerath           #+#    #+#             */
/*   Updated: 2021/12/13 20:00:49 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	init_complex(double x, double y)
{
	t_complex	complex;

	complex.re = x;
	complex.im = y;
	return (complex);
}

t_complex	sum_complex(t_complex complex1, t_complex complex2)
{
	t_complex	sum;

	sum.re = complex1.re + complex2.re;
	sum.im = complex1.im + complex2.im;
	return (sum);
}

t_complex	pow_complex(t_complex complex)
{
	t_complex	result;

	result.re = pow(complex.re, 2.0) - pow(complex.im, 2.0);
	result.im = 2 * complex.re * complex.im;
	return (result);
}

t_complex	tan_pow_complex(t_complex complex)
{
	t_complex	result;

	result.re = tan(pow(complex.re, 2.0) - pow(complex.im, 2.0));
	result.im = tan(2 * complex.re * complex.im);
	return (result);
}

t_complex	pow_complex_j(t_complex complex, t_complex complex2)
{
	t_complex	result;

	result.re = pow(complex.re, 2.0) - pow(complex.im, 2.0) + complex2.re;
	result.im = 2 * complex.re * complex.im + complex2.im;
	return (result);
}
