/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:55 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:57 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_run_op(t_list **a, t_list **b, t_op_type ot)
{
	if (ot == RA)
		ft_ra(a);
	else if (ot == RRA)
		ft_rra(a);
	else if (ot == RB)
		ft_rb(b);
	else if (ot == RRB)
		ft_rrb(b);
	else if (ot == RR)
		ft_rr(a, b);
	else if (ot == RRR)
		ft_rrr(a, b);
	else if (ot == PB)
		ft_pb(a, b);
	else if (ot == PA)
		ft_pa(a, b);
	else if (ot == SA)
		ft_sa(a);
	else if (ot == SB)
		ft_sb(b);
	else if (ot == SS)
		ft_ss(a, b);
}
