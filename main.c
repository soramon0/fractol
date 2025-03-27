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

void	mlx_data_free(t_mlx_data *data)
{
	if (data->mlx)
	{
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
		if (data->screen)
		{
			img_free(data->mlx, data->screen);
			data->screen = NULL;
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

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
	t_mlx_data		data;

	data = (t_mlx_data){NULL, NULL, NULL};
	set = parse_selected_set(argc, argv);
	if (set == SET_UNKNOWN)
		exit_usage();
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit_msg(STDERR_FILENO, "could not init mlx\n");
	data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, fractol_set_str(set));
	if (data.win == NULL)
	{
		mlx_data_free(&data);
		exit_msg(STDERR_FILENO, "could not create window\n");
	}
	data.screen = img_create(&data);
	if (data.screen == NULL)
	{
		mlx_data_free(&data);
		exit_msg(STDERR_FILENO, "could not create img\n");
	}
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	return (mlx_data_free(&data), EXIT_SUCCESS);
}
