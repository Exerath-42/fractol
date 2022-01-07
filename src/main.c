/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:29:01 by exerath           #+#    #+#             */
/*   Updated: 2022/01/07 04:09:31 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	finish(int n)
{
	if (n == 1)
		printf("work finished!\n");
	if (n == 0)
		printf("use parameters:\n[mandelbrot]\n[julia] [re] [im]\n[bfly]");
	exit(1);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	check_params(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia") \
		&& ft_strcmp(argv[1], "bfly"))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (check_params(argc, argv) == 0)
		finish(0);
	init_win(argc, argv);
	exit(0);
	return (0);
}
