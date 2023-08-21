/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_no_error_launcher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:28:38 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 22:38:30 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "no_error.h"

int	no_error_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "no_error", "no_error_test", &no_error_test);
	return (unit_test_run(unit));
}
