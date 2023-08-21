/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:25:38 by rponsonn          #+#    #+#             */
/*   Updated: 2022/01/09 21:59:05 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "atoi/atoi.h"
#include "diff/diff.h"
#include "isalpha/isalpha.h"
#include "isascii/isascii.h"
#include "strlen/strlen.h"

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= atoi_launcher();
	ret |= diff_launcher();
	ret |= isalpha_launcher();
	ret |= isascii_launcher();
	ret |= strlen_launcher();
	return (ret);
}
