/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:07:19 by gsap              #+#    #+#             */
/*   Updated: 2022/01/09 22:30:23 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_unit
{
	char			*func;
	char			*name;
	int				(*function)(void);
	struct s_unit	*next;
}	t_unit;

typedef struct s_run
{
	t_unit	*ptr;
	int		pid;
	int		status;
	int		res;
	int		i;
	int		compt;
	int		ok;
}	t_run;

//	list.c
t_unit	*unit_test_create(char *func, char *name, int (*function)(void));
void	unit_test_addlist(t_unit **list, char *func, char *name,
			int (*function)(void));
void	unit_test_del(t_unit *list);
int		unit_test_run(t_unit *list);
void	ft_exec_func(t_unit *list);

//	ft_error.c
int		ft_error(char *err);
void	*ft_free_lst(t_unit *list);
int		ft_free_all(t_run *data);
int		ft_free_unit_addlist(t_unit *ptr, char *error);

//	display.c
int		ft_display_error(t_run *data, t_unit *list);
int		ft_display(t_run *data, t_unit *list);
void	ft_print(t_unit *list, char *res);
int		ft_print_total(t_run *data);
t_run	*ft_init_data(t_run *data, t_unit *list);

// ft_utils.c
size_t	fr_strlen(const char *s);
char	*fr_strdup(const char *s1);
void	*fr_memcpy(void *dst, const void *src, size_t n);
void	fr_putnbr_fd(int n, int fd);
void	fr_putchar_fd(char c, int fd);

#endif
