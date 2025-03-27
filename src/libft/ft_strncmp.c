/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && c1[i] && c2[i] && c1[i] == c2[i])
		i++;
	return (c1[i] - c2[i]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	len = ft_strlen(s1);
	return (len == ft_strlen(s2) && ft_strncmp(s1, s2, len) == 0);
}
