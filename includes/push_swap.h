/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:53:16 by jealonso          #+#    #+#             */
/*   Updated: 2015/05/19 12:20:37 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# define P_C	1
# define P_V	2
# define P_N	4

typedef struct		s_val
{
	struct s_val	*next;
	struct s_val	*prev;
	int				data;
}					t_val;
typedef struct	s_i
{
	int			w;
	int			x;
	int			y;
	int			z;
}				t_i;
int		ft_error(char **av, int ac, int start);
void    ft_get_agrs(int ac, int *start, char **av, int option);
t_val	*push_a(t_val **chain, t_val **second, int *cmp, int option);
void	ft_sort(int	option, t_val *begin, t_val *end_list);
t_val   *rot_a(t_val **begin, t_val **second, int *cmp, int option);
t_val	*rrot_a(t_val **begin, t_val **second, int *cmp, int option);
t_i		*ft_init_index(t_i *var);
void	swap_a(t_val **chain, int *cmp, int opion);
void	push_b(t_val **second, int *cmp, int option);

#endif
