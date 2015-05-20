/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 11:31:06 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/20 17:37:43 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_error(char **av, int ac, int start)
{
	int index;

	index = start;
	while (index++ < ac && av[index])
	{
		if ((av[index][0] != '-' && ft_isdigit(av[index][1] == 0)) ||
				(ft_isdigit(av[index][0] == 0)))
		{
			ft_putstr("content no digit character\n");
			return (1);
		}
	}
	return (0);
}
