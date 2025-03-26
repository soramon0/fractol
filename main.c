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

void	usage(void)
{
	ft_printf_fd(STDERR_FILENO, "usage:\n");
	ft_printf_fd(STDERR_FILENO, "\t./fractol mandelbrot\n");
	exit_msg(EXIT_FAILURE, "\t./fractol julia <real> <i>\n");
}

int	main(int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		usage();
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		usage();
	if (argc != 4 || !ft_strcmp(argv[1], "julia"))
		usage();
	ft_printf("Set selected: %s\n", argv[1]);
	return (0);
}
