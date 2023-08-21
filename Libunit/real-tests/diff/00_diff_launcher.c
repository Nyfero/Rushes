/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_diff_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:58:09 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 20:43:28 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diff.h"

int	diff_launcher(void)
{
	t_unit	*unit;

	unit = NULL;
	unit_test_addlist(&unit, "diff", "diff_test_identical", \
	&diff_test_identical);
	unit_test_addlist(&unit, "diff", "diff_test_lessthan", \
	&diff_test_lessthan);
	unit_test_addlist(&unit, "diff", "diff_test_greaterthan", \
	&diff_test_greaterthan);
	return (unit_test_run(unit));
}
