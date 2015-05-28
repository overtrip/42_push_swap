/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 11:46:50 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/28 18:57:08 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdigit(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		++str;
	if (*str >= '0' && *str <= '9')
	{
		while (*str && str)
		{
			if (*str >= '0' && *str <= '9')
				++str;
			else
				return (0);
		}
		return (*str == '\0' ? 1 : 0);
	}
	return (0);
}
