/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_malloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:28:31 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 17:29:14 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAD_MALLOC_H
# define BAD_MALLOC_H

# include <stdlib.h>
# include "../../framework/inc/libunit.h"

int	bad_malloc_launcher(void);
int	bad_malloc_segfault(void);
int	bad_malloc(void);

#endif
