/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:47:57 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/17 06:50:07 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->stk[0] > a->stk[1])
			swap_a(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b, 0);
	else if (a->size == 5)
		sort_five(a, b);
	if (check_sorted(*a))
		exit(0);
}

void	sort_three(t_stack *a)
{
	if (a->stk[0] > a->stk[1])
	{
		if (a->stk[0] > a->stk[2])
			rot_a(a);
		if (a->stk[0] > a->stk[1])
			swap_a(a);
	}
	else
	{
		if (a->stk[1] > a->stk[2])
		{
			rev_rot_a(a);
			if (a->stk[0] > a->stk[1])
				swap_a(a);
		}
	}
}

void	sort_four(t_stack *a, t_stack *b, int min)
{
	if (a->stk[3] == min)
		rev_rot_a(a);
	else if (a->stk[2] == min)
		rot_a(a);
	if (a->stk[1] == min)
		rot_a(a);
	if (!check_sorted(*a))
	{
		push_b(a, b);
		sort_three(a);
		push_a(a, b);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (a->stk[3] == 0)
		rev_rot_a(a);
	if (a->stk[4] == 0)
		rev_rot_a(a);
	if (a->stk[2] == 0)
		rot_a(a);
	if (a->stk[1] == 0)
		rot_a(a);
	push_b(a, b);
	sort_four(a, b, 1);
	push_a(a, b);
}
