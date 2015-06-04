/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 11:31:06 by jealonso          #+#    #+#             */
/*   Updated: 2015/06/04 12:26:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_msg_error(const char *str, int option)
{
	(option & P_E) ? ft_putstr(str) : ft_putstr_fd("Error", 2);
	ft_putchar('\n');
	exit(1);
}

int		ft_size_val(char *str, int option)
{
	long	nb;

	nb = 0;
	while (str && *str)
	{
		if (*str >= '0' && *str <= '9')
			nb = nb * 10 + (*str - 48);
		else
			break ;
		++str;
	}
	if (nb >= INT_MAX)
		ft_msg_error("\n\tError: Content digit to big.\n\n", option);
	return (0);
}

void	ft_compstr(char *s1, char *s2, int option)
{
	if (*s1 == '-' || *s1 == '+')
		++s1;
	if (*s2 == '-' || *s2 == '+')
		++s2;
	while (*s1 && *s1 == '0')
		s1++;
	while (*s2 && *s2 == '0')
		s2++;
	if (*s1 == '\0' && *s2 == '\0')
		ft_msg_error("\n\tError: Content a duplicate digit.\n", option);
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
		ft_msg_error("\n\tError: Content a duplicate digit.\n", option);
}
