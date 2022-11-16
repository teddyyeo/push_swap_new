/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:00:01 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/17 06:51:12 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_swap(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}

void	rot_rot(t_stack *a, t_stack *b)
{
	rot_a(a);
	rot_b(b);
}

void	rev_rot_rot(t_stack *a, t_stack *b)
{
	rev_rot_a(a);
	rev_rot_b(b);
}
