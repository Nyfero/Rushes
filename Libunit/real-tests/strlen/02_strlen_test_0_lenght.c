/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_strlen_test_0_lenght.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:35:36 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 20:37:43 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen.h"

int	strlen_test_0_lenght(void)
{
	if (ft_strlen("") == 0)
		return (0);
	else
		return (-1);
}