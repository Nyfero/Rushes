/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:26:55 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 17:27:09 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bad_malloc/bad_malloc.h"

int	bad_malloc(void)
{
	char	*ptr;

	ptr = NULL;
	*ptr = 42;
	return (0);
}