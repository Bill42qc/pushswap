/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:52:21 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 19:08:42 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int	lst_size;

	check_if_sorted(*a);
	lst_size = ft_lstsize_chain(*a);
	if (lst_size == 2)
		ra(a);
	if (lst_size == 3)
		three_sort(a);
	if (lst_size == 4)
		four_sort(a, b);
	if (lst_size == 5)
		five_sort(a, b);
	if (lst_size > 5)
		big_sort(a, b);
}

void	three_sort(t_stack **a)
{
	if ((*a)->nbr < (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr
		&& (*a)->nbr < (*a)->next->next->nbr)
	{
		rra(a);
		sa(*a);
	}
	if ((*a)->nbr < (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		sa(*a);
		rra(a);
	}
	if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr < (*a)->next->next->nbr
		&& (*a)->nbr > (*a)->next->next->nbr)
		ra(a);
	if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr < (*a)->next->next->nbr
		&& (*a)->nbr < (*a)->next->next->nbr)
		sa(*a);
}

void	four_sort(t_stack **a, t_stack **b)
{
	int	smallest_pos;

	smallest_pos = lst_smallest_element(a);
	if (smallest_pos == 4)
	{
		rra(a);
		small_sort_combo(a, b);
	}
	if (smallest_pos == 3)
	{
		rra(a);
		rra(a);
		small_sort_combo(a, b);
	}
	if (smallest_pos == 2)
	{
		sa(*a);
		small_sort_combo(a, b);
	}
	if (smallest_pos == 1)
		small_sort_combo(a, b);
}

void	five_sort(t_stack **a, t_stack **b)
{
	int	smallest_pos;

	smallest_pos = lst_smallest_element(a);
	if (smallest_pos == 5)
	{
		rra(a);
		pb(a, b, 1);
		four_sort(a, b);
		pa(a, b);
	}
	if (smallest_pos == 4)
	{
		rra(a);
		rra(a);
		pb(a, b, 1);
		four_sort(a, b);
		pa(a, b);
	}
	five_sort2(a, b, smallest_pos);
}

void	five_sort2(t_stack **a, t_stack **b, int smallest_pos)
{
	if (smallest_pos == 3)
	{
		ra(a);
		ra(a);
		pb(a, b, 1);
		four_sort(a, b);
		pa(a, b);
	}
	if (smallest_pos == 2)
	{
		sa(*a);
		pb(a, b, 1);
		four_sort(a, b);
		pa(a, b);
	}
	if (smallest_pos == 1)
	{
		pb(a, b, 1);
		four_sort(a, b);
		pa(a, b);
	}
}
