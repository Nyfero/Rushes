/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:47:29 by gsap              #+#    #+#             */
/*   Updated: 2021/12/12 23:32:28 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	hotrace_proc(t_swt *swt, char *buf)
{
	char	*ret;
	char	**value_ptr;

	while (*buf != '\n')
	{
		ret = ft_create_index(buf);
		if (ret)
		{
			value_ptr = swt_place(swt, buf);
			buf = ret;
			ret = ft_create_index(buf);
			*value_ptr = buf;
		}
		buf = ret;
	}
	++buf;
	keys_proc(swt, buf);
}

void	keys_proc(t_swt *swt, char *buf)
{
	char	*ret;
	char	*value;

	while (*buf)
	{
		ret = ft_create_index(buf);
		value = swt_find(swt, buf);
		if (value)
		{
			ft_putstr(value);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			ft_putstr(buf);
			write(STDOUT_FILENO, NOT_FOUND, sizeof(NOT_FOUND) - 1);
		}
		buf = ret;
	}
}

int	main(void)
{
	t_swt	swt;
	char	*buf;

	swt_create(&swt, 20);
	buf = (char *)malloc(sizeof(char) * (MAX_INT));
	get_next_line(buf);
	hotrace_proc(&swt, buf);
	free(buf);
	free(swt.swb);
	return (0);
}

char	*get_next_line(char *buf)
{
	long int	rd;

	rd = read(0, buf, MAX_INT - 1);
	buf[rd] = 0;
	return (buf);
}

char	*ft_create_index(char *begin)
{
	unsigned long	*lbegin;
	unsigned long	v;

	lbegin = (unsigned long *)begin;
	while (*lbegin)
	{
		v = (*lbegin ^ MASK_0X0A);
		v = ~((((v & MASK_0X7F) + MASK_0X7F) | v) | MASK_0X7F);
		if (v)
		{
			begin = (char *)lbegin;
			while (v)
			{
				if (v & 0x80)
				{
					*begin = '\0';
					return (begin + 1);
				}
				++begin;
				v >>= 8;
			}
		}
		++lbegin;
	}
	return (NULL);
}
