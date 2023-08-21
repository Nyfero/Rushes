/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:20:01 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 21:51:57 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libunit.h"

int	ft_display_error(t_run *data, t_unit *list)
{
	int	signal;

	signal = WTERMSIG(data->status);
	if (signal == 11)
		ft_print(list, "[SIGSEGV]\n");
	else if (signal == 7)
		ft_print(list, "[SIGBUS]\n");
	data->compt++;
	return (-1);
}

int	ft_display(t_run *data, t_unit *list)
{
	if (data->status == 0)
	{
		ft_print(list, "[OK]\n");
		data->ok++;
	}
	else
		ft_print(list, "[KO]\n");
	data->compt++;
	if (data->status == 0 && data->i == 0)
		return (0);
	else
		return (-1);
}

void	ft_print(t_unit *list, char *res)
{
	write(1, list->func, fr_strlen(list->func));
	write(1, " : ", 3);
	write(1, list->name, fr_strlen(list->name));
	write(1, " : ", 3);
	write(1, res, fr_strlen(res));
}

int	ft_print_total(t_run *data)
{
	int	res;

	res = data->i;
	write(1, "\n\t", 2);
	fr_putnbr_fd(data->ok, 1);
	write(1, "/", 1);
	fr_putnbr_fd(data->compt, 1);
	write(1, " test(s) checked\n\n", 18);
	free(data);
	return (res);
}

t_run	*ft_init_data(t_run *data, t_unit *list)
{
	data = malloc(sizeof(t_run));
	if (!data)
	{
		ft_free_lst(list);
		exit(ft_error("Data failed\n"));
	}
	data->ptr = list;
	data->status = 0;
	data->res = 0;
	data->i = 0;
	data->compt = 0;
	data->ok = 0;
	return (data);
}
