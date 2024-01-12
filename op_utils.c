/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:46 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:48 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_op(t_op *op, int pass)
{
	op->pass = pass;
	op->a = NONE;
	op->b = NONE;
	op->comm = NONE;
	op->a_c = 0;
	op->b_c = 0;
	op->comm_c = 0;
	op->total_c = 0;
	op->cost.c_ra = 0;
	op->cost.c_rb = 0;
	op->cost.c_rra = 0;
	op->cost.c_rrb = 0;
}

void	ft_set_op_type(t_op *op, t_op_type a, t_op_type b, t_op_type comm)
{
	op->a = a;
	op->b = b;
	op->comm = comm;
}

static int	ft_comm_count(int op_c1, int op_c2)
{
	if (op_c1 < op_c2)
		return (op_c1);
	return (op_c2);
}

static void	ft_set_op_count(t_op *op, int comm_c, int c_a, int c_b)
{
	op->comm_c = comm_c;
	op->a_c = c_a - op->comm_c;
	op->b_c = c_b - op->comm_c;
}

void	ft_set_op_counts(t_op *op, t_op_comb comb)
{
	if (comb == C_RA_RB)
		ft_set_op_count(op, ft_comm_count(op->cost.c_ra, op->cost.c_rb),
			op->cost.c_ra, op->cost.c_rb);
	else if (comb == C_RA_RRB)
		ft_set_op_count(op, 0, op->cost.c_ra, op->cost.c_rrb);
	else if (comb == C_RRA_RB)
		ft_set_op_count(op, 0, op->cost.c_rra, op->cost.c_rb);
	else if (comb == C_RRA_RRB)
		ft_set_op_count(op, ft_comm_count(op->cost.c_rra, op->cost.c_rrb),
			op->cost.c_rra, op->cost.c_rrb);
}
