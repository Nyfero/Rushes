/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_bad_malloc_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:20:48 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 17:21:04 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_malloc.h"

int	bad_malloc_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "bad_malloc", "bad_malloc_segfault",
		&bad_malloc_segfault);
	return (unit_test_run(unit));
}
