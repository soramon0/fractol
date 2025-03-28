/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/05 14:07:37 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

int		ft_atoi(const char *nptr, int *valid);
int		ft_atod(const char *nptr, double *num);
int		ft_isdigit(int c);
int		ft_isspace(char c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *start, char *end, char join);
char	*ft_strsearch(char *haystack[], char *needle);
char	**ft_split_free(char **arr);

int		ft_vprintf_fd(va_list args, int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
int		ft_vprintf(va_list args, const char *format, ...);
int		ft_printf_fd(int fd, const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		ft_putstr_fd(char *str, int fd);
int		ft_putchr(char c);
int		ft_putchr_fd(char c, int fd);
int		ft_putstr(char *s);
int		ft_putnbr(int n, int fd);
int		ft_putunbr(unsigned int n, int fd);
int		ft_putnbr_hex(unsigned long num, int uppercase, int fd);
int		ft_putptr(void *num, int fd);

ssize_t	get_next_line(int fd, char **receiver);
ssize_t	ft_istrchr(const char *s, char c);

#endif
