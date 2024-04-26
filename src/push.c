/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:08:56 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/03 13:52:30 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide
void	pb(t_stack **a, t_stack **b, int print_id)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	if ((*a)->next == (*a))
		(*a) = NULL;
	else
	{
		(*a)->next->previous = (*a)->previous;
		(*a)->previous->next = (*a)->next;
		(*a) = (*a)->next;
	}
	pb2(b, tmp, print_id);
}

void	pb2(t_stack **b, t_stack *tmp, int print_id)
{
	if (*b)
	{
		tmp->next = (*b);
		tmp->previous = (*b)->previous;
		(*b)->previous->next = tmp;
		(*b)->previous = tmp;
	}
	else
	{
		tmp->next = tmp;
		tmp->previous = tmp;
	}
	(*b) = tmp;
	if (print_id == 1)
		ft_printf("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	pb(b, a, 0);
	ft_printf("pa\n");
}

/*one rotate here because the norminette exist ....*/

void	rr(t_stack **a, t_stack **b)
{
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	ft_printf("rb\n");
}

/*one check here because the norminette exist ....*/

void	check_no_double_string(char **av)
{
	int	i;

	i = 0;
	while (av[2][i])
	{
		if (av[2][i] == ' ')
			print_error();
		i++;
	}
}
