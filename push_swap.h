/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:05:57 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/17 06:54:54 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	*stk;
}	t_stack;

int		ft_atoi_new(const char *str, char *flag);

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

void	rot_a(t_stack *a);
void	rot_b(t_stack *b);
void	rev_rot_a(t_stack *a);
void	rev_rot_b(t_stack *b);

void	swap_swap(t_stack *a, t_stack *b);
void	rot_rot(t_stack *a, t_stack *b);
void	rev_rot_rot(t_stack *a, t_stack *b);

void	select_sort(int *arr, int size);
int		check_sorted(t_stack a);
void	normalize(int *a, int size);
void	radix(t_stack *a, t_stack *b);

void	small_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b, int min);
void	sort_five(t_stack *a, t_stack *b);
#endif
