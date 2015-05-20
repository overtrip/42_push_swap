/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:40:37 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/19 19:17:44 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_i		*ft_init_index(t_i *index)
{
	index->w = 0;
	index->x = 1;
	index->y = 0;
	index->z = 1;
	return (index);
}

int		ft_get_opt(char **av, t_i ind)
{
	const int	tab[3] = {P_C, P_N, P_V};
	const char	tabc[4] = {'c', 'n', 'v', '\0'};
	int			ret;

	ret = 0;
	while (av[ind.x][++ind.y])
	{
		ind.z = -1;
		while (tabc[++ind.z])
		{
			if (av[ind.x][ind.y] == tabc[ind.z])
			{
				ret |= tab[ind.z];
				break ;
			}
		}
		if (ind.z == 3 || (tabc[ind.z] != av[ind.x][ind.y]
					&& ft_isdigit(av[ind.x][ind.y]) == 0))
		{
			ft_putstr("\n\tError: Option not recognized.\n");
			return (-1);
		}
	}
	return (ret);
}

int		ft_get_option(char **av, int *start)
{
	int	option;
	t_i	ind;

	option = 0;
	ft_init_index(&ind);
	while (av[ind.x][0] == '-' && av[ind.x])
	{
		if (!av[ind.x++][1])
			continue ;
		--ind.x;
		if (av[ind.x][1] == '-' && av[ind.x][2])
			return (-1);
		if (av[ind.x][1] == '-' && !av[ind.x][2])
		{
			++ind.x;
			break ;
		}
		option |= ft_get_opt(av, ind);
		++ind.x;
	}
	*start = ind.x - 1;
	return (option);
}

int		main(int ac, char **av)
{
	int	option;
	int	start;

	start = 1;
	if (ac > 1)
	{
		if ((option = ft_get_option(av, &start)) < 0)
			return (-1);
		if (ft_error(av, ac, start) == 1)
			return (-1);
		ft_get_agrs(ac, &start, av, option);
	}
	else
		ft_putstr("\n\tError: Content a void parameters.\n");
	ft_putchar('\n');
	return (0);
}
