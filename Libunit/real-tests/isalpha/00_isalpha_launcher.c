/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_isalpha_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:44:00 by rponsonn          #+#    #+#             */
/*   Updated: 2022/01/09 20:44:30 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isalpha.h"

int	isalpha_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "isalpha", "isalpha_test_lowercase", \
	&isalpha_test_lowercase);
	unit_test_addlist(&unit, "isalpha", "isalpha_test_uppercase", \
	&isalpha_test_uppercase);
	unit_test_addlist(&unit, "isalpha", "isalpha_test_numbers", \
	&isalpha_test_numbers);
	unit_test_addlist(&unit, "isalpha", "isalpha_test_negative", \
	&isalpha_test_negative);
	return (unit_test_run(unit));
}
