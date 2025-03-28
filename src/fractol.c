/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_mlx_data *d, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			max_iter;
	int			i;

	z.x = 0.0;
	z.y = 0.0;
	c.x = (map_x(d, x) * d->zoom) + d->move_x;
	c.y = (map_y(d, y) * d->zoom) + d->move_y;
	i = 0;
	max_iter = 42;
	while (i < max_iter)
	{
		z = sum_complex(sequre_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map_color(max_iter, i, 255);
			update_img_pixel(d->screen, x, y, color);
			return ;
		}
		i++;
	}
	update_img_pixel(d->screen, x, y, encode_rgba(0, 0, 0, 255));
}

void	render_julia(t_mlx_data *d, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			max_iter;
	int			i;

	z.x = (map_x(d, x) * d->zoom) + d->move_x;
	z.y = (map_y(d, y) * d->zoom) + d->move_y;
	c.x = d->julia_input[0];
	c.y = d->julia_input[1];
	i = 0;
	max_iter = 42;
	while (i < max_iter)
	{
		z = sum_complex(sequre_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map_color(max_iter, i, 255);
			update_img_pixel(d->screen, x, y, color);
			return ;
		}
		i++;
	}
	update_img_pixel(d->screen, x, y, encode_rgba(0, 0, 0, 255));
}

int	fractol_render(t_mlx_data *d)
{
	int	x;
	int	y;

	x = 0;
	mlx_clear_window(d->mlx, d->win);
	while (x < d->win_w)
	{
		y = 0;
		while (y < d->win_h)
		{
			if (d->fractol_set == SET_MANDELBROT)
				render_mandelbrot(d, x, y);
			else if (d->fractol_set == SET_JULIA)
				render_julia(d, x, y);
			else
				return (-1);
			y++;
		}
		x++;
	}
	return (mlx_put_image_to_window(d->mlx, d->win, d->screen->src, 0, 0));
}
