/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflow(int r, int digit, int sign)
{
	if (sign > 0)
	{
		if (r > INT_MAX / 10 || (r == INT_MAX / 10 && digit > INT_MAX % 10))
			return (1);
	}
	else
	{
		if (r < INT_MIN / 10 || (r == INT_MIN / 10 && digit < INT_MIN % 10))
			return (1);
	}
	return (0);
}

static int	parse_integer_part(char **nptr, int *r, int *s)
{
	while (ft_isdigit(**nptr))
	{
		*r = (*r * 10) + (**nptr - '0');
		if (is_overflow(*r, **nptr, *s) != 0)
			return (-1);
		(*nptr)++;
	}
	return (0);
}

static void	parse_decimal_part(const char **nptr, double *d, double *pow)
{
	int	decimal_digits;

	decimal_digits = 0;
	while (ft_isdigit(**nptr) && decimal_digits < 15)
	{
		*pow *= 0.1;
		*d += (**nptr - '0') * (*pow);
		(*nptr)++;
		decimal_digits++;
	}
}

int	ft_atod(const char *nptr, double *num)
{
	int		r;
	double	d;
	double	pow;
	int		s;

	r = 0;
	d = 0.0;
	s = 1;
	pow = 1.0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			s = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr) || parse_integer_part((char **)&nptr, &r, &s) == -1)
		return (-1);
	if (*nptr == '.' || *nptr == ',')
		nptr++;
	parse_decimal_part(&nptr, &d, &pow);
	*num = (r + d) * s;
	return (0);
}
