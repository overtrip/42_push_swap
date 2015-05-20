/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 13:50:00 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/17 16:48:41 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcolor(char *color, char *str)
{
	write(1, color, ft_strlen(color));
	write(1, str, ft_strlen(str));
	write(1, RESET, 4);
}
