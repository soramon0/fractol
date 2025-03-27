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

void	update_fractol_pixel(t_mlx_data *d, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			max_iter;
	int			i;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map_x(d, x);
	c.y = map_y(d, y);
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
			update_fractol_pixel(d, x, y);
			y++;
		}
		x++;
	}
	return (mlx_put_image_to_window(d->mlx, d->win, d->screen->src, 0, 0));
}
