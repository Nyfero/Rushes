/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_diff_test_identical.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:58:35 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 18:33:44 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diff.h"

int	diff_test_identical(void)
{
	if (ft_diff(0, 0) == 0)
		return (0);
	else
		return (-1);
}
