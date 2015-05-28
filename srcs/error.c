/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 11:31:06 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/28 19:31:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_msg_error(const char *str, int option)
{
	(option & P_E) ? ft_putstr(str) : ft_putstr("Error");
	ft_putchar('\n');
	exit(1);
}

int		ft_size_val(char *str, int option)
{
	size_t	nb;

	nb = 0;
	while (str && *str++)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (nb > INT_MAX)
				ft_msg_error("\n\tErreur: Content digit to big.\n\n", option);
			nb = nb * 10 + (*str + 48);
		}
	}
	return (0);
}

int		ft_compstr(char *s1, char *s2)
{
	int len1;
	int len2;

	if (*s1 == '-' || *s1 == '+')
		++s1;
	if (*s2 == '-' || *s2 == '+')
		++s2;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (ft_memcmp(s1, s2, MAX(len1, len2)));
}

int		ft_mult(char **av, int ac, int start, int option)
{
	int	nb;
	int	i;

	nb = start - 1;
	while (nb++ < ac && av[nb])
	{
		i = nb;
		while (av[++i])
		{
			if (ft_memcmp(av[nb], av[i],
						(ft_strlen(av[nb]) > ft_strlen(av[i])) ?
						ft_strlen(av[nb]) : ft_strlen(av[i])) == 0 ||
					ft_compstr(av[nb], av[i]) == 0)
				ft_msg_error("\n\tErreur: Content a doubloon digit.\n", option);
		}
	}
	return (0);
}

int		ft_error(char **av, int ac, int start, int option)
{
	int index;

	index = start;
	while (index++ < ac && av[index])
	{
		if (ft_strisdigit(av[index]) == 0)
		{
			ft_msg_error("\n\tError: Content no digit character.\n", option);
			return (1);
		}
		ft_size_val(av[index], option);
		ft_mult(av, ac, start, option);
	}
	return (0);
}
