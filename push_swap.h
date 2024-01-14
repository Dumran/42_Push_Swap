/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:49 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/14 15:06:10 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft/libft.h"

typedef enum e_op_type
{
	NONE,
	RA,
	RRA,
	RB,
	RRB,
	RR,
	RRR,
	PB,
	PA,
	SA
}		t_op_type;

typedef enum e_op_comb
{
	C_RA_RB,
	C_RA_RRB,
	C_RRA_RB,
	C_RRA_RRB
}		t_op_comb;

typedef struct s_min_op_cost
{
	int			cost;
	t_op_comb	comb;
}		t_min_op_cost;

typedef struct s_op_cost
{
	int			c_ra;
	int			c_rra;
	int			c_rb;
	int			c_rrb;
}		t_op_cost;

typedef struct s_op
{
	int			pass;
	t_op_type	a;
	t_op_type	b;
	t_op_type	comm;
	int			a_c;
	int			b_c;
	int			comm_c;
	int			total_c;
	t_op_cost	cost;
}		t_op;

typedef enum e_three_case
{
	CASE_SLM,
	CASE_MLS,
	CASE_MSL,
	CASE_LSM,
	CASE_LMS
}		t_three_case;

void			ft_dispose(void *stack);
void			ft_exitsafe(void *stack, int exit_code);
void			ft_exiterr(int err_no, void *stack);

void			ft_check_param(int ac, char **av);
int				ft_is_duplicate(t_list	*stack);
int				ft_is_sorted(t_list *stack);

int				ft_cal_mov_a_op(t_list *a, int pass, int op);
int				ft_cal_mov_b_op(t_list *b, int pass, int op);
t_min_op_cost	ft_get_min_op_cost(t_op_cost *cost);

int				ft_get_pivot(t_list *a);
int				ft_count_passenger(t_list *a, int pivot);

void			ft_init_op(t_op *op, int pass);
void			ft_set_op_type(t_op *op, t_op_type a,
					t_op_type b, t_op_type comm);
void			ft_set_op_counts(t_op *op, t_op_comb comb);
void			ft_cal_op_cost(t_op *op, t_list *a, t_list *b);
void			ft_prepare_b_for_pa(t_list **a, t_list **b);
int				ft_is_min_b(t_list *b);
void			ft_set_op(t_op *op, t_list *a, t_list *b);
int				ft_lstmin(t_list *stack);

void			ft_run_op(t_list **a, t_list **b, t_op_type ot);
void			ft_run_op_n(t_list **a, t_list **b,
					t_op_type op_type, int count);
t_op			ft_select_op(t_list *a, t_list *b, int pivot);

void			ft_case_five(t_list **a, t_list **b, int pivot);
void			ft_start_inner(t_list **a, t_list **b,
					int pivot, int pass_count);

void			ft_sa(t_list **a);
void			ft_sb(t_list **b);
void			ft_ss(t_list **a, t_list **b);
void			ft_pa(t_list **a, t_list **b);
void			ft_pb(t_list **a, t_list **b);
void			ft_ra(t_list **a);
void			ft_rb(t_list **b);
void			ft_rr(t_list **a, t_list **b);
void			ft_rra(t_list **a);
void			ft_rrb(t_list **b);
void			ft_rrr(t_list **a, t_list **b);

#endif
