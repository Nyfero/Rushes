/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:47:40 by gsap              #+#    #+#             */
/*   Updated: 2021/12/12 23:22:28 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

inline size_t	ft_strlen(char *str)
{
	unsigned long	*lstr;
	size_t			i;
	unsigned long	v;

	lstr = (unsigned long *)str;
	v = ~((((*lstr & MASK_0X7F) + MASK_0X7F) | *lstr) | MASK_0X7F);
	while (!v)
	{
		++lstr;
		v = ~((((*lstr & MASK_0X7F) + MASK_0X7F) | *lstr) | MASK_0X7F);
	}
	i = (void *)lstr - (void *)str;
	while (v)
	{
		++i;
		v >>= 8;
	}
	return (i);
}

inline void	ft_putstr(char *str)
{
	unsigned long	*lstr;
	size_t			i;
	unsigned long	v;

	lstr = (unsigned long *)str;
	v = ~((((*lstr & MASK_0X7F) + MASK_0X7F) | *lstr) | MASK_0X7F);
	while (!v)
	{
		++lstr;
		v = ~((((*lstr & MASK_0X7F) + MASK_0X7F) | *lstr) | MASK_0X7F);
	}
	i = (void *)lstr - (void *)str - 1;
	while (v)
	{
		++i;
		v >>= 8;
	}
	write(STDOUT_FILENO, str, i);
}
