/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_isascii_test_negative.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:02:02 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 20:18:17 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isascii.h"

int	isascii_test_negative(void)
{
	if (ft_isascii(-2) == 0)
		return (0);
	else
		return (-1);
}