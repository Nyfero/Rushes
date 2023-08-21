/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:24:03 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 22:31:02 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libunit.h"

t_unit	*unit_test_create(char *func, char *name, int (*function)(void))
{
	t_unit	*list;

	if (!func || !name || !(*(function)))
	{
		ft_error("Unable to create a list\n");
		return (NULL);
	}
	list = malloc(sizeof(t_unit));
	if (!list)
		return (NULL);
	list->name = NULL;
	list->next = NULL;
	list->func = fr_strdup(func);
	if (!list->func)
		return (ft_free_lst(list));
	list->name = fr_strdup(name);
	if (!list->name)
		return (ft_free_lst(list));
	list->function = function;
	return (list);
}

void	unit_test_addlist(t_unit **list, char *func, char *name,
	int (*function)(void))
{
	t_unit	*ptr;

	if (!list || !func || !name || !(*function))
		exit(ft_free_unit_addlist(*list, "Unable to add a list\n"));
	if (!*list)
	{
		*list = unit_test_create(func, name, function);
		if (!*list)
			exit(ft_free_unit_addlist(*list, "Malloc failed\n"));
	}
	else
	{
		ptr = *list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = unit_test_create(func, name, function);
		if (!ptr->next)
			exit(ft_free_unit_addlist(*list, "Malloc failed\n"));
	}
}

void	unit_test_del(t_unit *list)
{
	t_unit	*tmp;

	if (!list)
		exit(ft_error("Nothing to clear\n"));
	while (list)
	{
		tmp = list->next;
		free(list->func);
		free(list->name);
		free(list);
		list = NULL;
		list = tmp;
	}
}

int	unit_test_run(t_unit *list)
{
	t_run	*data;

	if (!list)
		return (ft_error("No list submitted\n"));
	data = NULL;
	data = ft_init_data(data, list);
	while (list)
	{
		data->pid = fork();
		if (data->pid == -1)
			exit(ft_free_all(data));
		if (data->pid == 0)
			ft_exec_func(list);
		else
		{
			wait(&data->status);
			if (WIFSIGNALED(data->status))
				data->i = ft_display_error(data, list);
			else
				data->i = ft_display(data, list);
		}
		list = list->next;
	}
	unit_test_del(data->ptr);
	return (ft_print_total(data));
}

void	ft_exec_func(t_unit *list)
{
	int	res;

	res = (*list->function)();
	if (res == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
