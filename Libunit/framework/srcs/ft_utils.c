/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:49 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 21:51:39 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libunit.h"

size_t	fr_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*fr_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	size = fr_strlen(s1);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ptr = fr_memcpy(ptr, s1, size + 1);
	return (ptr);
}

void	*fr_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*xfr;

	i = 0;
	if (dst == src)
		return (dst);
	ptr = (unsigned char *)dst;
	xfr = (unsigned char *)src;
	while (i < n)
	{
		*ptr++ = *xfr++;
		i++;
	}
	return (dst);
}

void	fr_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		fr_putchar_fd('-', fd);
		i = -i;
	}
	if (i == 0)
		fr_putchar_fd('0', fd);
	else if (i > 9)
	{
		fr_putnbr_fd(i / 10, fd);
		fr_putchar_fd((i % 10) + '0', fd);
	}
	else
		fr_putchar_fd(i + '0', fd);
}

void	fr_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
