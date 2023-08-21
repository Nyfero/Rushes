/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:25:08 by rponsonn          #+#    #+#             */
/*   Updated: 2022/01/09 21:58:53 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "bad_malloc/bad_malloc.h"
#include "bus_error/bus_error.h"
#include "error/error.h"
#include "no_error/no_error.h"

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= no_error_launcher();
	ret |= error_launcher();
	ret |= bad_malloc_launcher();
	ret |= bus_error_launcher();
	return (ret);
}
