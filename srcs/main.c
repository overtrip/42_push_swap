/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:40:37 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/29 12:52:16 by jealonso         ###   ########.fr       */
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
	const int	tab[5] = {P_C, P_N, P_V, P_E, P_T};
	const char	tabc[6] = {'c', 'n', 'v', 'e', 't', '\0'};
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
		if (ind.z == 5 || (tabc[ind.z] != av[ind.x][ind.y]
					&& ft_isdigit(av[ind.x][ind.y]) == 0))
			ft_msg_error("\n\tError: Option not recognized.\n", ret);
	}
	return (ret);
}

int		ft_get_option(char **av, int *start)
{
	int	option;
	t_i	ind;

	option = 0;
	ft_init_index(&ind);
	while (av[ind.x] && av[ind.x][0] == '-')
	{
		if (!av[ind.x++][1])
			continue ;
		--ind.x;
		if (av[ind.x][1] == '-' && av[ind.x][2])
			return (-1);
		if (ft_strisdigit(av[ind.x]) == 1)
			break ;
		option |= ft_get_opt(av, ind);
		++ind.x;
	}
	*start = ind.x - 1;
	return (option);
}

int		ft_error(char **av, int ac, int start, int option)
{
	int index;

	index = start;
	while (index++ < ac && av[index])
	{
		if (ft_strisdigit(av[index]) == 0)
			ft_msg_error("\n\tError: Content no digit character.\n", option);
		ft_mult(av, ac, start, option);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	option;
	int	start;

	option = 0;
	start = 1;
	if (ac > 1)
	{
		if ((option = ft_get_option(av, &start)) < 0)
			return (-1);
		if (ft_error(av, ac, start, option) == 1)
			return (-1);
		ft_get_agrs(ac, &start, av, option);
	}
	else
		ft_msg_error("\n\tError: Content a void parameter.\n", option);
	ft_putchar('\n');
	return (0);
}
