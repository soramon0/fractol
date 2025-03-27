/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/05 14:07:37 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_msg(int status, char *fmt, ...)
{
	va_list	args;

	if (fmt != NULL)
	{
		va_start(args, fmt);
		ft_vprintf_fd(args, STDERR_FILENO, fmt);
		va_end(args);
	}
	exit(status);
}

void	exit_err(char *fmt, ...)
{
	va_list	args;

	if (fmt != NULL)
	{
		va_start(args, fmt);
		ft_vprintf_fd(args, STDERR_FILENO, fmt);
		va_end(args);
	}
	exit(EXIT_FAILURE);
}

void	exit_usage(void)
{
	ft_printf_fd(STDERR_FILENO, "usage:\n");
	ft_printf_fd(STDERR_FILENO, "\tfractol mandelbrot\n");
	exit_msg(EXIT_FAILURE, "\tfractol julia <real> <i>\n");
}
