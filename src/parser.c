/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*fractol_set_str(t_fractol_set set)
{
	static char	*str = "unknown";

	if (set < 0 || set >= SET_UNKNOWN)
		return (NULL);
	if (set == SET_MANDELBROT)
		str = "mandelbrot";
	if (set == SET_JULIA)
		str = "julia";
	return (str);
}

t_fractol_set	fractol_set(char *set)
{
	if (ft_strcmp(set, fractol_set_str(SET_MANDELBROT)))
		return (SET_MANDELBROT);
	if (ft_strcmp(set, fractol_set_str(SET_JULIA)))
		return (SET_JULIA);
	return (SET_UNKNOWN);
}

t_fractol_set	parse_selected_set(int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		return (SET_UNKNOWN);
	if (argc == 2 && ft_strcmp(argv[1], fractol_set_str(SET_MANDELBROT)))
		return (SET_MANDELBROT);
	if (argc == 4 && ft_strcmp(argv[1], fractol_set_str(SET_JULIA)))
		return (SET_JULIA);
	return (SET_UNKNOWN);
}
