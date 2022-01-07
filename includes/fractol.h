/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:29:04 by exerath           #+#    #+#             */
/*   Updated: 2022/01/07 02:11:43 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "bind_key.h"
# include "../libmlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# define HEIGHT 800
# define WIDTH	800

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_complex{
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractal{
	t_complex	c;
	t_complex	j;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	double		step_im;
	double		step_re;
	int			color;
	int			name_num;
	int			iter;
}				t_fractal;

typedef struct s_win{
	void		*mlx;
	void		*mlx_win;
	t_image		*image;
	t_fractal	*fractal;
}				t_win;

t_complex	init_complex(double x, double y);
t_complex	pow_complex(t_complex complex);
t_complex	sum_complex(t_complex complex1, t_complex complex2);
t_complex	pow_complex(t_complex complex);
t_complex	pow_complex_j(t_complex complex, t_complex complex2);
t_win		*init_win(int argc, char **argv);
t_image		*init_image(void *mlx);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		draw(t_win *win);
t_fractal	*init_fractal(int argc, char **argv);
int			ft_strcmp(const char *s1, const char *s2);
int			choose_fractal(t_fractal *fractal, int argc, char **argv);
int			mandelbrot(t_fractal *fractal);
int			closer(int key);
int			zoom(int wheel, int x, int y, t_win *win);
void		hooks(t_win *win);
void		motion(int key, t_win *win);
int			key_cheker(int key, t_win *win);
char		*ft_itoa(int n);
void		instruction(t_win *win);
void		finish(int n);
int			julia(t_fractal *fractal);
int			bfly(t_fractal *fractal);
void		ft_putstr(char *s);

#endif