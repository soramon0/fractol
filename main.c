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
#include <stdio.h>

int	handle_events(int keysym, t_mlx_data *data)
{
	double	offset;

	if (keysym == XK_Escape)
	{
		mlx_data_free(data);
		exit_msg(EXIT_SUCCESS, "closing window\n");
	}
	offset = 0.2;
	if (keysym == XK_Right)
		data->move_x -= (offset * data->zoom);
	else if (keysym == XK_Left)
		data->move_x += (offset * data->zoom);
	else if (keysym == XK_Up)
		data->move_y -= (offset * data->zoom);
	else if (keysym == XK_Down)
		data->move_y += (offset * data->zoom);
	return (fractol_render(data));
}

int	handle_mouse(int button, int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	if (button == Button5)
		data->zoom *= 0.95;
	else if (button == Button4)
		data->zoom *= 1.05;
	return (fractol_render(data));
}

int	handle_close(t_mlx_data *data)
{
	mlx_data_free(data);
	exit_msg(EXIT_SUCCESS, "closing window\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol_set	set;
	t_mlx_data		*data;
	double			input[2];

	set = parse_selected_set(argc, argv);
	if (set == SET_UNKNOWN)
		exit_usage();
	if (set == SET_JULIA)
	{
		if (ft_atod(argv[2], input) != 0 || ft_atod(argv[3], input + 1) != 0)
			return (exit_err("input is not a valid float\n"), EXIT_FAILURE);
	}
	data = mlx_data_create(fractol_set_str(set), WIN_W, WIN_H, input);
	if (data == NULL)
		return (EXIT_FAILURE);
	fractol_render(data);
	mlx_key_hook(data->win, handle_events, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, handle_close, data);
	mlx_loop(data->mlx);
	return (mlx_data_free(data), EXIT_SUCCESS);
}
