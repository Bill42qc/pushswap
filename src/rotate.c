/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:23:35 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 19:08:45 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	if (!*a)
		return ;
	(*a) = (*a)->next;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (!*b)
		return ;
	(*b) = (*b)->next;
	ft_printf("rb\n");
}

void	rra(t_stack **a)
{
	if (!*a)
		return ;
	(*a) = (*a)->previous;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (!*b)
		return ;
	(*b) = (*b)->previous;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	(*a) = (*a)->previous;
	(*b) = (*b)->previous;
	ft_printf("rrr\n");
}
