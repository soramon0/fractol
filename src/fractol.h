/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/05 14:07:37 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <X11/Xutil.h>
# include <mlx.h>

# define WIN_W 500
# define WIN_H 500

typedef struct s_img
{
	void		*src;
	char		*pixels;
	int			bits_per_pixel;
	int			endian;
	int			size_len;
}				t_img;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_img		*screen;
}				t_mlx_data;

typedef enum e_fractol_set
{
	SET_MANDELBROT,
	SET_JULIA,
	SET_UNKNOWN,
}				t_fractol_set;

void			exit_msg(int status, char *fmt, ...);
void			exit_usage(void);
t_fractol_set	parse_selected_set(int argc, char *argv[]);
char			*fractol_set_str(t_fractol_set set);

t_mlx_data		*mlx_data_create(char *title, int width, int height);
void			mlx_data_free(t_mlx_data *data);
t_img			*img_create(t_mlx_data *data);
void			img_free(void *mlx, t_img *img);
void			update_img_pixel(t_img *img, int x, int y, int color);
int				encode_rgb(unsigned char red, unsigned char green,
					unsigned char blue);

#endif
