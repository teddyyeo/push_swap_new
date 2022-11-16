/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:25:40 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/17 06:51:26 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	select_sort(int *arr, int size)
{
	int	idx;
	int	jdx;
	int	min_idx;

	idx = 0;
	while (idx < size - 1)
	{
		min_idx = idx;
		jdx = idx + 1;
		while (jdx < size)
		{
			if (arr[jdx] < arr[min_idx])
				min_idx = jdx;
			jdx++;
		}
		swap(&arr[min_idx], &arr[idx]);
		idx++;
	}
}

int	check_sorted(t_stack a)
{
	int	max;
	int	idx;

	max = a.size;
	idx = 0;
	while (idx + 1 < max)
	{
		if (a.stk[idx] > a.stk[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

void	normalize(int *a, int size)
{
	int	*b;
	int	idx;
	int	jdx;

	b = malloc(sizeof(int) * size);
	idx = 0;
	while (idx < size)
	{
		b[idx] = a[idx];
		idx++;
	}
	select_sort(b, size);
	idx = 0;
	while (idx < size)
	{
		jdx = 0;
		while (jdx < size)
		{
			if (a[idx] == b[jdx])
				a[idx] = jdx;
			jdx++;
		}
		idx++;
	}
	free(b);
}

void	radix(t_stack *a, t_stack *b)
{
	int	max_bit;
	int	idx;
	int	jdx;
	int	size;

	max_bit = 1;
	size = a->size;
	while ((a->size - 1) >> max_bit != 0)
		max_bit++;
	idx = 0;
	while (idx < max_bit)
	{
		jdx = 0;
		while (jdx < size)
		{
			if ((a->stk[0] >> idx) & 1)
				rot_a(a);
			else
				push_b(a, b);
			jdx++;
		}
		while (b->size != 0)
			push_a(a, b);
		idx++;
	}
}
