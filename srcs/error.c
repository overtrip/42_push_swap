/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 11:31:06 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/29 12:52:14 by jealonso         ###   ########.fr       */
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
		else
			break ;
	}
	return (0);
}

void	ft_compstr(char *s1, char *s2, int option)
{
	if (*s1 == '-' || *s1 == '+')
		++s1;
	if (*s2 == '-' || *s2 == '+')
		++s2;
	while (*s1 && *s2)
	{
		if (*s1 == '0')
			++s1;
		if (*s2 == '0')
			++s2;
		else
			break ;
	}
	if (*s1 == '\0' && *s2 == '\0')
		ft_msg_error("\n\tErreur: Content a doubloon digit.\n", option);
}

void	ft_compstr2(char *s1, char *s2, int option)
{
	if (*s1 == '+')
		++s1;
	if (*s2 == '+')
		++s2;
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			++s1;
			++s2;
		}
		else
			break ;
	}
	if (*s1 == '\0' && *s2 == '\0')
		ft_msg_error("\n\tErreur: Content a doubloon digit.\n", option);
}

void	ft_mult(char **av, int ac, int start, int option)
{
	int	nb;
	int	i;
	int chiffre;
	int	current;

	nb = start - 1;
	while (nb++ < ac && av[nb])
	{
		chiffre = 0;
		current = -1;
		i = nb;
		while (av[++i])
		{
			ft_compstr2(av[nb], av[i], option);
			ft_compstr(av[nb], av[i], option);
			if (ft_memcmp(av[nb], av[i], MAX(av[nb], av[i]) == 0))
				ft_msg_error("\n\tErreur: Content a doubloon digit.\n", option);
		}
		ft_size_val(av[nb], option);
	}
}
