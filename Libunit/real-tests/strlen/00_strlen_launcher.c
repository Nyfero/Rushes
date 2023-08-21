/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:40:10 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 22:46:45 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen.h"

int	strlen_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "strlen", "strlen_test_10_length",
		&strlen_test_10_lenght);
	unit_test_addlist(&unit, "strlen", "strlen_test_0_length",
		&strlen_test_0_lenght);
	unit_test_addlist(&unit, "strlen", "strlen_test_null", &strlen_test_null);
	unit_test_addlist(&unit, "strlen", "strlen_test_40", &strlen_test_40);
	return (unit_test_run(unit));
}
