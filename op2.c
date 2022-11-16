/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:13:19 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/16 18:00:30 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_stack *a)
{
	int	temp;
	int	idx;

	if (a->size < 2)
		return ;
	temp = a->stk[0];
	idx = 0;
	while (idx < a->size - 1)
	{
		a->stk[idx] = a->stk[idx + 1];
		idx++;
	}
	a->stk[idx] = temp;
	ft_printf("ra\n");
}

void	rot_b(t_stack *b)
{
	int	temp;
	int	idx;

	if (b->size < 2)
		return ;
	temp = b->stk[0];
	idx = 0;
	while (idx < b->size - 1)
	{
		b->stk[idx] = b->stk[idx + 1];
		idx++;
	}
	b->stk[idx] = temp;
	ft_printf("rb\n");
}

void	rev_rot_a(t_stack *a)
{
	int	temp;
	int	idx;

	if (a->size < 2)
		return ;
	temp = a->stk[a->size - 1];
	idx = a->size - 1;
	while (idx >= 0)
	{
		a->stk[idx + 1] = a->stk[idx];
		idx--;
	}
	a->stk[0] = temp;
	ft_printf("rra\n");
}

void	rev_rot_b(t_stack *b)
{
	int	temp;
	int	idx;

	if (b->size < 2)
		return ;
	temp = b->stk[b->size - 1];
	idx = b->size - 1;
	while (idx >= 0)
	{
		b->stk[idx + 1] = b->stk[idx];
		idx--;
	}
	b->stk[0] = temp;
	ft_printf("rrb\n");
}
