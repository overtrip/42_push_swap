/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 14:29:35 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/29 11:37:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_val **second, int *cmp, int option)
{
	if (*second)
	{
		while (*second && ++*cmp)
		{
			(!(option & P_C)) ? ft_strcolor(RESET, "pa ") :
				ft_strcolor(YELLOW, "pa ");
			*second = (*second)->next;
		}
	}
	if (option & P_N)
	{
		ft_strcolor(GREEN, "\n\toperations use: ");
		ft_putnbr(*cmp);
		ft_putchar('\n');
	}
}

t_val	*push_a(t_val **chain, t_val **second, int *cmp, int option)
{
	t_val	*end_list;
	t_val	*save;

	end_list = (*chain)->prev;
	save = *second;
	if (!(*second))
	{
		*second = *chain;
		(*chain)->prev->next = NULL;
		(*second)->prev = NULL;
	}
	else
	{
		while ((*second)->next)
			*second = (*second)->next;
		(*second)->next = *chain;
		(*chain)->next = NULL;
		(*chain)->prev = *second;
		*second = (*second)->next;
		end_list->next = NULL;
		*second = save;
	}
	(!(option & P_C)) ? ft_strcolor(RESET, "pb ") : ft_strcolor(CYAN, "pb ");
	++*cmp;
	return (end_list);
}

void	swap_a(t_val **chain, int *cmp, int option)
{
	int	tmp;

	tmp = (*chain)->data;
	(*chain)->data = (*chain)->prev->data;
	(*chain)->prev->data = tmp;
	(!(option & P_C)) ? ft_strcolor(RESET, "sa ") : ft_strcolor(YELLOW, "sa ");
	++*cmp;
}

t_val	*rrot_a(t_val **begin, t_val **second, int *cmp, int option)
{
	t_val	*end_list;

	end_list = (*second)->prev;
	(*second)->next = (*begin);
	(*second)->prev = NULL;
	(*begin)->prev = (*second);
	*begin = *second;
	*second = end_list;
	(*second)->next = NULL;
	++*cmp;
	(!(option & P_C)) ? ft_strcolor(RESET, "rra ") : ft_strcolor(GREEN, "rra ");
	return (*second);
}

t_val	*rot_a(t_val **begin, t_val **second, int *cmp, int option)
{
	t_val	*save;

	(*second)->next = (*begin);
	(*begin)->prev = (*second);
	save = (*begin)->next;
	save->prev = NULL;
	(*begin)->next = NULL;
	*second = *begin;
	*begin = save;
	++*cmp;
	(!(option & P_C)) ? ft_strcolor(RESET, "ra ") : ft_strcolor(RED, "ra ");
	return (*second);
}
