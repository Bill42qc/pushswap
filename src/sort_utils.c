/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:29:36 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 20:53:48 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_chain(t_stack *lst)
{
	unsigned int	size;
	t_stack			*tmp;

	if (!lst)
		return (0);
	size = 0;
	tmp = lst;
	while (lst->next != tmp)
	{
		lst = lst->next;
		size++;
	}
	size++;
	return (size);
}

void	check_if_sorted(t_stack *a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = a;
	tmp = current;
	while (current->next != tmp)
	{
		if (current->nbr > current->next->nbr)
			return ;
		current = current->next;
	}
	free_stack(a);
	exit(0);
}

int	lst_smallest_element(t_stack **a)
{
	t_stack	*current;
	int		smallest_int;
	int		smallest_pos;

	smallest_int = INT_MAX;
	current = (*a);
	smallest_pos = 1;
	while (current)
	{
		if (current->nbr < smallest_int)
			smallest_int = current->nbr;
		current = current->next;
		if (current->nbr == (*a)->nbr)
			break ;
	}
	current = (*a);
	while (current)
	{
		if (current->nbr == smallest_int)
			break ;
		smallest_pos++;
		current = current->next;
	}
	return (smallest_pos);
}

void	small_sort_combo(t_stack **a, t_stack **b)
{
	pb(a, b, 1);
	three_sort(a);
	pa(a, b);
}

void	ra_or_rra(t_stack **a, int lst_size, int smallest_int)

{
	if (find_pos_sort((*a), smallest_int) < (lst_size / 2))
		rb(a);
	else
		rrb(a);
}
