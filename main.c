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

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_data_free(data);
		exit_msg(EXIT_SUCCESS, "closing window\n");
	}
	return (fractol_render(data));
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
