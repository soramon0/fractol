/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/05 14:07:37 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
// min[0] old_min
// max[0] old_max
// min[1] new_min
// max[1] new_max
*/
double	map_num(double num, double min[2], double max[2])
{
	return ((max[1] - min[1]) * (num - min[0]) / (max[0] - min[0]) + min[1]);
}

double	map_x(t_mlx_data *d, double x)
{
	double	min[2];
	double	max[2];

	min[0] = 0;
	min[1] = -2;
	max[0] = d->win_w;
	max[1] = 2;
	return (map_num(x, min, max));
}

double	map_y(t_mlx_data *d, double y)
{
	double	min[2];
	double	max[2];

	min[0] = 0;
	min[1] = 2;
	max[0] = d->win_h;
	max[1] = -2;
	return (map_num(y, min, max));
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	sequre_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
