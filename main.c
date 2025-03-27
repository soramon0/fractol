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
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_data_free(data);
		exit_msg(EXIT_SUCCESS, "closing window\n");
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol_set	set;
	t_mlx_data		data;

	data = (t_mlx_data){NULL, NULL};
	set = parse_selected_set(argc, argv);
	if (set == SET_UNKNOWN)
		exit_usage();
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit_msg(STDERR_FILENO, "could not init mlx\n");
	data.win = mlx_new_window(data.mlx, 400, 300, fractol_set_str(set));
	if (data.win == NULL)
	{
		mlx_data_free(&data);
		exit_msg(STDERR_FILENO, "could not create window\n");
	}
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	return (mlx_data_free(&data), EXIT_SUCCESS);
}
