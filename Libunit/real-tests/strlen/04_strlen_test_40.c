/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_strlen_test_40.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:35:36 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 21:55:57 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen.h"

int	strlen_test_40(void)
{
	if (ft_strlen("0123456789012345678901234567890123456789") == 40)
		return (0);
	else
		return (-1);
}
