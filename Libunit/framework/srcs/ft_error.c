/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:28:36 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 22:21:32 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libunit.h"

int	ft_error(char *err)
{
	write(2, "Error : ", 8);
	write(2, err, fr_strlen(err));
	return (-1);
}

void	*ft_free_lst(t_unit *list)
{
	if (list == NULL)
		return (NULL);
	if (list->func)
		free(list->func);
	if (list->name)
		free(list->name);
	free(list);
	return (NULL);
}

int	ft_free_all(t_run *data)
{
	if (data == NULL)
		return (ft_error("fork"));
	unit_test_del(data->ptr);
	free(data);
	return (ft_error("fork"));
}

int	ft_free_unit_addlist(t_unit *ptr, char *error)
{
	unit_test_del(ptr);
	return (ft_error(error));
}
