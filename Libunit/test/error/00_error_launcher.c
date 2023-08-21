/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error_launcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:25:30 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 17:25:32 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	error_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "error", "error_test", &error_test);
	return (unit_test_run(unit));
}
