/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_bad_malloc_segfault.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:21:18 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 17:23:18 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_malloc.h"

int	bad_malloc_segfault(void)
{
	if (bad_malloc() == 0)
		return (0);
	else
		return (-1);
}