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

# include "../include/mlx/mlx.h"
# include "libft/libft.h"
# include <X11/Xutil.h>

# define WIN_W 600
# define WIN_H 600

typedef enum e_fractol_set
{
	SET_MANDELBROT,
	SET_JULIA,
	SET_UNKNOWN,
}					t_fractol_set;

typedef struct s_complex
{
	double			x;
	double			y;
}					t_complex;

typedef struct s_img
{
	void			*src;
	char			*pixels;
	int				bits_per_pixel;
	int				size_len;
	int				endian;
}					t_img;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*win;
	t_img			*screen;
	int				win_w;
	int				win_h;
	double			move_x;
	double			move_y;
	double			zoom;
	t_fractol_set	fractol_set;
}					t_mlx_data;

void				exit_msg(int status, char *fmt, ...);
void				exit_err(char *fmt, ...);
void				exit_usage(void);
t_fractol_set		parse_selected_set(int argc, char *argv[]);
char				*fractol_set_str(t_fractol_set set);
t_fractol_set		fractol_set(char *set);
int					fractol_render(t_mlx_data *data);

t_mlx_data			*mlx_data_create(char *title, int width, int height);
void				mlx_data_free(t_mlx_data *data);
t_img				*img_create(t_mlx_data *data);
void				img_free(void *mlx, t_img *img);
void				update_img_pixel(t_img *img, int x, int y, int color);
int					encode_rgba(unsigned char red, unsigned char green,
						unsigned char blue, unsigned char alpha);
double				map_color(double max_iter, double iter,
						unsigned char alpha);
double				map_num(double num, double min[2], double max[2]);
double				map_x(t_mlx_data *d, double x);
double				map_y(t_mlx_data *d, double y);
t_complex			sum_complex(t_complex z1, t_complex z2);
t_complex			sequre_complex(t_complex z);

#endif
