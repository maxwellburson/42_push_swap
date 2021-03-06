/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:48:12 by mburson           #+#    #+#             */
/*   Updated: 2017/01/31 04:48:13 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>
#include <push_swap.h>

void			free_instructions(char ***instr)
{
	int		i;

	i = 0;
	while ((*instr)[i])
	{
		free((*instr)[i]);
		i++;
	}
	free(*instr);
	*instr = NULL;
}

static void		del_num(void *ptr, size_t size)
{
	UNUSED(size);
	free(ptr);
}

void			free_stack(t_list **stack)
{
	if (stack && *stack)
		ft_lstdel(stack, &del_num);
}

void			free_stack_one(t_list **stack)
{
	if (stack && *stack)
		ft_lstdelone(stack, &del_num);
}
