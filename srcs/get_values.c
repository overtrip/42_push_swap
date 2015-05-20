/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:26:32 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/17 19:15:36 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_val	*ft_create_elem(char *data)
{
	t_val	*new;

	if (!(new = (t_val *)malloc(sizeof(t_val))))
		return (NULL);
	new->data = ft_atoi(data);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_add_list(t_val **begin, t_val *current)
{
	if (!(*begin))
	{
		*begin = current;
		return ;
	}
	else
	{
		(*begin)->prev = current;
		current->next = (*begin);
		(*begin) = current;
	}
}

t_val	*ft_end_list(t_val **begin)
{
	t_val	*end;

	end = *begin;
	while (end->next)
		end = end->next;
	return (end);
}

void	ft_get_agrs(int ac, int *start, char **av, int option)
{
	t_val	*begin;

	begin = NULL;
	while (++(*start) < ac)
		ft_add_list(&begin, ft_create_elem(av[*start]));
	if (!(begin))
	{
		ft_putstr("\n\tError: no values set.\n");
		return ;
	}
	ft_sort(option, begin, ft_end_list(&begin));
}
