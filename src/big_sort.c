/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:03:25 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 20:52:22 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	box_sort(a, b);
	big_int_sort(a, b);
	while ((*a)->nbr != 1)
		ra((a));
}

void	big_int_sort(t_stack **a, t_stack **b)
{
	int	lst_size;
	int	smallest_int;
	int	bigger_int;

	smallest_int = 1;
	lst_size = ft_lstsize_chain(*b);
	bigger_int = lst_size;
	while (lst_size > 1)
	{
		lst_size = ft_lstsize_chain(*b);
		if ((*b)->nbr == bigger_int)
		{
			pa(a, b);
			bigger_int -= 1;
		}
		else
			ra_or_rra(b, lst_size, bigger_int);
	}
}

int	find_pos_sort(t_stack *head, int nbr)
{
	t_stack	*current;
	t_stack	*tmp;
	int		pos;

	if (head == NULL)
		return (0);
	pos = 1;
	current = head;
	tmp = head;
	while (tmp->nbr != nbr)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	box_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		lst_size;
	int		divisor;

	tmp = (*a);
	lst_size = ft_lstsize_chain(*a);
	if (lst_size < 200)
		divisor = 7;
	if (lst_size >= 200)
		divisor = 20;
	lst_size = ft_lstsize_chain(*a);
	while (lst_size)
	{
		box_utils(a, b, lst_size, divisor);
		lst_size = ft_lstsize_chain(*a);
	}
}

void	box_utils(t_stack **a, t_stack **b, int lst_size, int divisor)
{
	int	count;

	count = lst_size;
	while (count)
	{
		if (bucket_completed(a, count, lst_size, divisor) != 1)
			break ;
		if ((*a)->nbr >= (lst_size - (lst_size / divisor)))
		{
			pb(a, b, 1);
		}
		else if ((*a)->nbr <= (lst_size / divisor))
		{
			pb(a, b, 1);
			rb(b);
		}
		else
			ra(a);
		count--;
	}
}
