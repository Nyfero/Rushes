/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_bus_error_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:24:32 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 17:26:41 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bus_error.h"

int	bus_error_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "bus_error", "bus_error_sigbus",
		&bus_error_sigbus);
	return (unit_test_run(unit));
}
