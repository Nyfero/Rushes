/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:43:40 by rponsonn          #+#    #+#             */
/*   Updated: 2022/01/09 22:41:18 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFF_H
# define DIFF_H
# include "../../framework/inc/libunit.h"
# include "../../libft/includes/libft.h"

int	diff_launcher(void);
int	diff_test_identical(void);
int	diff_test_lessthan(void);
int	diff_test_greaterthan(void);

#endif
