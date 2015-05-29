/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 17:13:50 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/29 11:38:11 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_decresing(t_val *begin, t_i *var)
{
	int		nb_elems;
	int		sorted;
	t_val	*prev;

	prev = NULL;
	nb_elems = 0;
	sorted = 1;
	var->z = begin ? begin->data : var->z;
	while (begin && ++nb_elems)
	{
		var->z = (var->z > begin->data) ? begin->data : var->z;
		prev = begin;
		begin = begin->next;
		if (begin && prev->data < begin->data)
			sorted = 0;
	}
	var->x = (var->z == prev->data) ? 1 : 0;
	var->y = nb_elems;
	return (sorted);
}

int		ft_find(t_val *begin, t_i *var)
{
	int	cmp;
	int save;

	cmp = (var->y % 2) == 0 ? (var->y / 2) : (var->y / 2 + 1);
	while (begin && cmp--)
	{
		if (begin->data == var->z)
			break ;
		begin = begin->next;
	}
	while (begin && begin->next)
	{
		save = begin->data;
		begin = begin->next;
	}
	if (begin)
		var->w = (save < begin->data ? 1 : 0);
	return ((cmp > 0) ? 1 : 0);
}

void	ft_aff_stat(t_val *chain, t_val *second, int option)
{
	(P_C & option) ? ft_strcolor(YELLOW, "\n\n\t Pile A: ") :
		ft_putstr("\n\n\t Pile A: ");
	while (chain)
	{
		ft_putnbr(chain->data);
		ft_putchar(' ');
		chain = chain->next;
	}
	(P_C & option) ? ft_strcolor(YELLOW, "\n\t Pile B: ") :
		ft_putstr("\n\t Pile B: ");
	while (second)
	{
		ft_putnbr(second->data);
		ft_putchar(' ');
		second = second->next;
	}
	ft_putchar('\n');
}

void	ft_stat_pile(t_val ***chain, t_val ***second, int *cmp, int option)
{
	t_val	*current_a;

	current_a = **chain;
	while (current_a && current_a->next)
		current_a = current_a->next;
	while (*second && **second && (**second)->next)
		(**second) = (**second)->next;
	while (*second && **second && ++(*cmp))
	{
		(!(option & P_C)) ? ft_strcolor(RESET, "pa ") :
			ft_strcolor(YELLOW, "pa ");
		current_a->next = (**second);
		current_a = current_a->next;
		(**second) = (**second)->prev;
		if (**second)
		{
			(**second)->next->prev = current_a;
			(**second)->next = NULL;
		}
		if (option & P_V)
			ft_aff_stat(**chain, **second, option);
	}
}

void	ft_reelaff(t_val **chain, t_val **second, int *cmp, int option)
{
	ft_stat_pile(&chain, &second, cmp, option);
	(P_C & option) ? ft_strcolor(BLUE, "\n\n\tFinally stack: ") :
		ft_putstr("\n\n\tFinally stack: ");
	while ((*chain))
	{
		ft_putnbr((*chain)->data);
		ft_putchar(' ');
		(*chain) = (*chain)->next;
	}
	ft_putchar('\n');
	if (P_N & option)
	{
		(P_C & option) ? ft_strcolor(GREEN, "\n\tOperation use: ") :
			ft_putstr("\n\tOperation use: ");
		ft_putnbr(*cmp);
		ft_putchar('\n');
	}
}
