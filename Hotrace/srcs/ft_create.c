/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:56:23 by geargenc          #+#    #+#             */
/*   Updated: 2021/12/12 23:05:10 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	swt_create(t_swt *swt, size_t power)
{
	int	i;

	swt->buckets = 0x01 << power;
	swt->entries = swt->buckets * 16;
	swt->bytes = swt->entries * 17;
	swt->swb = (t_swt_bucket *)malloc(swt->bytes);
	swt->swk = (char **)(swt->swb + swt->buckets);
	swt->swv = swt->swk + swt->entries;
	i = -1;
	while ((size_t)++i < swt->buckets)
		swt->swb[i].m = _mm_set1_epi8(EMPTY);
}

char	**swt_place(t_swt *swt, char *key)
{
	t_swt_process	s;

	s.hash.v = hashfunc(key);
	s.i = s.hash.v % swt->buckets;
	s.tri = 0;
	while (++s.tri)
	{
		s.match = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_set1_epi8(EMPTY),
					swt->swb[s.i].m));
		s.bit = 0;
		while (s.match)
		{
			if (s.match & 0x01)
			{
				swt->swb[s.i].vec[s.bit] = (unsigned char)s.hash.meta;
				swt->swk[(s.i << 4) | s.bit] = key;
				return (&(swt->swv[(s.i << 4) | s.bit]));
			}
			s.match >>= 1;
			++s.bit;
		}
		s.i = (s.i + s.tri) % swt->buckets;
	}
	__builtin_unreachable();
}

char	*swt_find(t_swt *swt, char *key)
{
	t_swt_process	s;

	s.hash.v = hashfunc(key);
	s.i = s.hash.v % swt->buckets;
	s.tri = 0;
	while (++s.tri)
	{
		s.match = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_set1_epi8(s.hash.meta),
					swt->swb[s.i].m));
		s.bit = 0;
		while (s.match)
		{
			if ((s.match & 0x01)
				&& (ft_strequ(key, swt->swk[(s.i << 4) | s.bit])))
				return (swt->swv[(s.i << 4) | s.bit]);
			s.match >>= 1;
			++s.bit;
		}
		s.match = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_set1_epi8(EMPTY),
					swt->swb[s.i].m));
		if (s.match)
			return (NULL);
		s.i = (s.i + s.tri) % swt->buckets;
	}
	__builtin_unreachable();
}
