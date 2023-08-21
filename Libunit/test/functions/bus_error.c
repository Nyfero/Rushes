/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bus_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:27:15 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 21:58:17 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Forced Bus error (harder to trigger than you'd think)
*/

int	bus_error(void)
{
	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	return (0);
}
