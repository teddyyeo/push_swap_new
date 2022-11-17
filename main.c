/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:20:01 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/17 14:58:58 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_checker(int argc, char **argv)
{
	int		idx;
	char	c;

	while (argc > 1)
	{
		idx = 0;
		c = argv[argc - 1][idx];
		if (c != '-' && !ft_isdigit(c))
		{
			ft_printf("Error1\n");
			exit(0);
		}
		while (c)
		{
			if (!ft_isdigit(c) && idx != 0)
			{
				ft_printf("Error2\n");
				exit(0);
			}
			idx++;
			c = argv[argc - 1][idx];
		}
		argc--;
	}
}

void check_dupe(t_stack a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size -1)
	{
		j = i + 1;
		while (j < a.size)
		{
			if (a.stk[i] == a.stk[j])
			{
				ft_printf("Error3\n");
				exit(0);
			}
			j++;
		}
		i++;
	}

}
int	ft_atoi_new(const char *str, char *flag)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign *= (44 - *str++);
	while (*str >= '0' && *str <= '9')
	{
		if (num > 214748364)
			*flag = 1;
		else if (num == 214748364 && *str == '8' && sign == 1)
			*flag = 1;
		else if (num == 214748364 && *str > '8')
			*flag = 1;
		num = num * 10 + *str++ - 48;
	}
	num *= sign;
	return (num);
}

void print_stack(t_stack a, t_stack b)
{
	int i = 0;
	while (i < a.size || i < b.size)
	{
		if (i < a.size && i < b.size)
			ft_printf("%d       %d\n", a.stk[i], b.stk[i]);
		else if (i < a.size)
			ft_printf("%d\n", a.stk[i]);
		else if (i < b.size)
			ft_printf("        %d\n", b.stk[i]);
		i++;
	}
	ft_printf("--      --\n");
	ft_printf("a       b\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	flag;

	flag = 0;
	if (argc < 2)
		return (0);
	input_checker(argc, argv);
	a.stk = malloc(sizeof(int) * (argc - 1));
	b.stk = malloc(sizeof(int) * (argc - 1));
	if (a.stk == NULL || b.stk == NULL)
		return (1);
	a.size = argc - 1;
	b.size = 0;
	while (argc > 0)
	{
		a.stk[argc - 2] = ft_atoi_new(argv[argc - 1], &flag);
		if (flag == 1)
		{
			ft_printf("Error4\n");
			return (0);
		}
		argc--;
	}
	check_dupe(a);
	normalize(a.stk, a.size);
	if (check_sorted(a))
		exit(0);
	sort_n(&a, &b);
	print_stack(a, b);
	//small_sort(&a, &b);
	//radix(&a, &b);
	free(a.stk);
	free(b.stk);
	return (0);
}
