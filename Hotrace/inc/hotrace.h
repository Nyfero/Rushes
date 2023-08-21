/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:58:11 by gsap              #+#    #+#             */
/*   Updated: 2021/12/12 23:15:58 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <emmintrin.h>
# include <immintrin.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>

/*
**	Debug
*/

# include <stdio.h>
# include <locale.h>

/*
**	---
*/

# define MASK_0X7F 0x7F7F7F7F7F7F7F7F
# define MASK_0X0A 0x0a0a0a0a0a0a0a0a
# define MAX_INT 2147483647
# define EMPTY 0b10000000
# define NOT_FOUND ": Not found.\n"

typedef union s_swt_hash
{
	uint64_t		v;
	struct
	{
		uint64_t	meta : 7;
		uint64_t	unused;
	};
}					t_swt_hash;

typedef union u_swt_bucket
{
	__m128i			m;
	unsigned char	vec[sizeof(__m128i)];
}					t_swt_bucket;

typedef struct s_swt
{
	size_t			buckets;
	size_t			entries;
	size_t			bytes;
	t_swt_bucket	*swb;
	char			**swk;
	char			**swv;
}					t_swt;

typedef struct s_swt_process
{
	t_swt_hash		hash;
	size_t			i;
	size_t			tri;
	int				match;
	int				bit;
}					t_swt_process;

uint64_t			hashfunc(char *str);
int					ft_strequ(char *s1, char *s2);
void				swt_create(t_swt *swt, size_t power);
char				**swt_place(t_swt *swt, char *key);
char				*swt_find(t_swt *swt, char *key);

//  hotrace.c
void				hotrace_proc(t_swt *swt, char *buf);
void				keys_proc(t_swt *swt, char *buf);
int					main(void);
char				*get_next_line(char *buf);
char				*ft_create_index(char *buf);

//  ft_str_utils.c
size_t				ft_strlen(char *str);
void				ft_putstr(char *str);

#endif