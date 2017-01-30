/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 22:14:22 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 22:14:23 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <checker.h>
#include <unistd.h>
#include <stdlib.h>

void	del_num(void *ptr, size_t size)
{
	free(ptr);
}

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	//add_arguments(argv, &a);
	//execute_instructions(&a, &b);
	if (solve_check(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstdel(&a, &del_num);
	ft_lstdel(&b, &del_num);
	return (0);
}
