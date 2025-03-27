/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fractol.h"

int	color_screen(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			update_img_pixel(data->screen, x, y, color);
			y++;
		}
		x++;
	}
	return (mlx_put_image_to_window(data->mlx, data->win, data->screen->src, 0,
			0));
}

int	handle_input(int keysym, t_mlx_data *data)
{
	int	r;

	r = 0;
	if (keysym == XK_Escape)
	{
		mlx_data_free(data);
		exit_msg(EXIT_SUCCESS, "closing window\n");
	}
	if (keysym == XK_r)
		r = color_screen(data, encode_rgb(255, 0, 0));
	if (keysym == XK_g)
		r = color_screen(data, encode_rgb(0, 255, 0));
	if (keysym == XK_b)
		r = color_screen(data, encode_rgb(0, 0, 255));
	return (r);
}

int	main(int argc, char *argv[])
{
	t_fractol_set	set;
	t_mlx_data		*data;

	set = parse_selected_set(argc, argv);
	if (set == SET_UNKNOWN)
		exit_usage();
	data = mlx_data_create(fractol_set_str(set), WIN_W, WIN_H);
	if (data == NULL)
		return (EXIT_FAILURE);
	mlx_key_hook(data->win, handle_input, data);
	mlx_loop(data->mlx);
	return (mlx_data_free(data), EXIT_SUCCESS);
}
