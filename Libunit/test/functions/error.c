/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:27:27 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 17:27:37 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**test function that always returns a non zero value
*/

int	error(void)
{
	if (1 == 2)
		return (0);
	else
		return (-1);
}
