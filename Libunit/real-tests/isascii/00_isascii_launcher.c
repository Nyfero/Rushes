/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_isascii_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:00:38 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 20:48:49 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isascii.h"

int	isascii_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "isascii", "isascii_test_valid", \
	&isascii_test_valid);
	unit_test_addlist(&unit, "isascii", "isascii_test_zero", \
	&isascii_test_zero);
	unit_test_addlist(&unit, "isascii", "isascii_test_negative", \
	&isascii_test_negative);
	return (unit_test_run(unit));
}
