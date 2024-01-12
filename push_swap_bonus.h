/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:57 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:23:54 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "lib/libft/libft.h"

typedef enum e_op_type
{
	RA,
	RRA,
	RB,
	RRB,
	RR,
	RRR,
	PB,
	PA,
	SA,
	SB,
	SS
}		t_op_type;

void		ft_check_param(int ac, char **av);
int			ft_is_sorted(t_list *stack);
int			ft_is_duplicate(t_list	*stack);

void		ft_dispose(void *stack);
void		ft_exitsafe(void *stack, int exit_code);
void		ft_exiterr(int err_no, void *stack);

void		ft_pa(t_list **a, t_list **b);
void		ft_pb(t_list **a, t_list **b);
void		ft_rra(t_list **a);
void		ft_rrb(t_list **b);
void		ft_rrr(t_list **a, t_list **b);
void		ft_ra(t_list **a);
void		ft_rb(t_list **b);
void		ft_rr(t_list **a, t_list **b);
void		ft_sa(t_list **a);
void		ft_sb(t_list **b);
void		ft_ss(t_list **a, t_list **b);

void		ft_run_op(t_list **a, t_list **b, t_op_type ot);
int			ft_is_valid_inst(const char *inst);
long long	ft_atoi_l(const char *str);

#endif