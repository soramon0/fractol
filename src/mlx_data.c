/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_data_free(t_mlx_data *data)
{
	if (data != NULL)
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
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			data->mlx = NULL;
		}
		free(data);
	}
}

t_mlx_data	*mlx_data_create(char *title, int width, int height)
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	if (data == NULL)
		return (NULL);
	data->fractol_set = fractol_set(title);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (mlx_data_free(data), exit_err("mlx_init failed\n"), NULL);
	data->win_w = width;
	data->win_h = height;
	if (data->win_w <= 100 || data->win_h <= 100)
	{
		width = 800;
		height = 800;
	}
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, title);
	if (data->win == NULL)
		return (mlx_data_free(data), exit_err("window create failed\n"), NULL);
	data->screen = img_create(data);
	if (data->screen == NULL)
		return (mlx_data_free(data), exit_err("img create failed\n"), NULL);
	return (data);
}
