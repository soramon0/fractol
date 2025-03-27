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
# include "mlx.h"
# include <X11/Xutil.h>

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
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

#endif
