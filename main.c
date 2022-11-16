/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:20:01 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/17 07:06:33 by tayeo            ###   ########.fr       */
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
		while (c)
		{
			if (!ft_isdigit(c) && c != '-' && !(c > 8 && c < 14) && c != ' ')
				exit(0);
			idx++;
			c = argv[argc - 1][idx];
		}
		argc--;
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
	{
		sign *= (44 - *str);
		str++;
	}
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
			ft_printf("Error\nNumber is not int\n");
			return (0);
		}
		argc--;
	}
	if (check_sorted(a))
		exit(0);
	normalize(a.stk, a.size);
	small_sort(&a, &b);
	radix(&a, &b);
	free(a.stk);
	free(b.stk);
	return (0);
}
