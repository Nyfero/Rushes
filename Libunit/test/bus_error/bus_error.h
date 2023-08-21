/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bus_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:26:14 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 21:46:16 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**https://discord.com/channels/774300457157918772/
**774300457694003235/929497975896547349
*/
#ifndef BUS_ERROR_H
# define BUS_ERROR_H

# include <stdlib.h>
# include "../../framework/inc/libunit.h"

int	bus_error_launcher(void);
int	bus_error_sigbus(void);
int	bus_error(void);

#endif
