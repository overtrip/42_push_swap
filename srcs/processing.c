/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 17:13:50 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/20 17:27:26 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_decresing(t_val *begin, t_i *var)
{
	int	nb_elems;
	int	sorted;
	t_val *prev;

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

void	ft_sort(int option, t_val *begin, t_val *end_list)
{
	t_val	*second;
	t_i		var;
	int		find;
	int		cmp;
	int i;

	second = NULL;
	cmp = 0;
	ft_init_index(&var);
	while ( (i  = ft_decresing(begin, &var)) == 0)
	{
		find = ft_find(begin, &var);
		if (var.x == 1)
			end_list = push_a(&end_list, &second, &cmp, option);
		else if (var.w == 1 && var.y == 3)
			swap_a(&end_list, &cmp, option);
		else if (find == 1 && var.x == 0)
			end_list = rot_a(&begin, &end_list, &cmp, option);
		else if (find == 0)
			end_list = rrot_a(&begin, &end_list, &cmp, option);
	}
	push_b(&second, &cmp, option);
}
