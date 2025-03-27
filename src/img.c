/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_free(void *mlx, t_img *img)
{
	if (img != NULL)
	{
		mlx_destroy_image(mlx, img->src);
		free(img);
	}
}

t_img	*img_create(t_mlx_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->src = mlx_new_image(data->mlx, WIN_W, WIN_H);
	if (img->src == NULL)
		return (free(img), NULL);
	img->pixels = mlx_get_data_addr(img->src, &img->bits_per_pixel,
			&img->size_len, &img->endian);
	if (img->pixels == NULL)
		return (free(img->src), free(img), NULL);
	return (img);
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	update_img_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->size_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->pixels)) = color;
}
