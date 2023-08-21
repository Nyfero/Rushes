/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:42:50 by rponsonn          #+#    #+#             */
/*   Updated: 2022/01/09 20:42:52 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_H
# define ATOI_H
# include "../../framework/inc/libunit.h"
# include "../../libft/includes/libft.h"

int	atoi_launcher(void);
int	atoi_test_negative(void);
int	atoi_test_positive(void);
int	atoi_test_zero(void);
int	atoi_test_large_positive(void);
int	atoi_test_large_negative(void);

#endif
