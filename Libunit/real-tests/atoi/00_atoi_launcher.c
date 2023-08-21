/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:55:42 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 20:42:25 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

int	atoi_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "atoi", "atoi_test_negative", &atoi_test_negative);
	unit_test_addlist(&unit, "atoi", "atoi_test_positive", &atoi_test_positive);
	unit_test_addlist(&unit, "atoi", "atoi_test_zero", &atoi_test_zero);
	unit_test_addlist(&unit, "atoi", "atoi_test_large_positive", \
	&atoi_test_large_positive);
	unit_test_addlist(&unit, "atoi", "atoi_test_large_negative", \
	&atoi_test_large_negative);
	return (unit_test_run(unit));
}
