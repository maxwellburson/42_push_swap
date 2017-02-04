/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 22:44:36 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 22:44:38 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>

# define BUFF_SIZE 8

# define FLAG_VERBOSE 0x1

# define UNUSED(x) (void)(x)

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10


typedef struct	s_state
{
	t_list	**instr;
	t_list	**a;
	t_list	**b;
}				t_state;

extern int					g_flags;
extern const char * const 	g_instr[];
extern int (* const			g_func[])(t_list **a, t_list **b);

int		execute_instructions(t_list **a, t_list **b, char **instr);
int		solve_check(t_list *a, t_list *b);
int		get_instructions(char ***instr_return);

/*
** add_arguments.c
*/
int		add_arguments(int argc, char **argv, t_list **a);

/*
** /solve/
*/
int		solve(t_list **instr, t_list **a, t_list **b);
int		path_to_smallest(t_list *stack);

/*
** free.c
*/
void	free_instructions(char ***instr);
void	free_stack(t_list **stack);

/*
** ./instructions/
*/
int		exec_sa(t_list **a, t_list **b);
int		exec_sb(t_list **a, t_list **b);
int		exec_ss(t_list **a, t_list **b);
int		exec_pa(t_list **a, t_list **b);
int		exec_pb(t_list **a, t_list **b);
int		exec_ra(t_list **a, t_list **b);
int		exec_rb(t_list **a, t_list **b);
int		exec_rr(t_list **a, t_list **b);
int		exec_rra(t_list **a, t_list **b);
int		exec_rrb(t_list **a, t_list **b);
int		exec_rrr(t_list **a, t_list **b);

/*
** verbose.c (-v)
*/
void	print_starting_stack(t_list *stack);
void	print_instructions(char **instr);
void	print_stacks(t_list *a, t_list *b);
void	print_instr_res(t_list **a, t_list **b, char const *instr);

#endif