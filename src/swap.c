/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:55 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 20:53:35 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first 2 element of stack a
void	sa(t_stack *a)
{
	int	tmp;

	tmp = 0;
	if (a && a->next)
	{
		tmp = a->next->nbr;
		a->next->nbr = a->nbr;
		a->nbr = tmp;
	}
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int	tmp;

	tmp = 0;
	if (b && b->next)
	{
		tmp = b->next->nbr;
		b->next->nbr = b->nbr;
		b->nbr = tmp;
	}
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = 0;
	if (a && a->next)
	{
		tmp = a->next->nbr;
		a->next->nbr = a->nbr;
		a->nbr = tmp;
	}
	tmp = 0;
	if (b && b->next)
	{
		tmp = b->next->nbr;
		b->next->nbr = b->nbr;
		b->nbr = tmp;
	}
	ft_printf("ss\n");
}
