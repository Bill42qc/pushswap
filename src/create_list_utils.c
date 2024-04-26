/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:52:27 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 19:09:01 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verify that the new arg is not already an existing list node.
int	check_duplicate(t_stack *head, int nbr)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->nbr == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

//create a new node on the list
t_stack	*create_node(int nbr, int pos)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->nbr = nbr;
	node->pos = pos;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

//bubble sort and give the pos to the struct
void	find_pos(t_stack *head)
{
	t_stack	*current;
	t_stack	*stack;
	int		pos;

	if (head == NULL)
		return ;
	pos = 1;
	current = head;
	while (current != NULL)
	{
		pos = 1;
		stack = head;
		while (stack != NULL)
		{
			if (stack->nbr < current->nbr)
				pos++;
			stack = stack->next;
		}
		current->pos = pos;
		current = current->next;
	}
}

void	swap_nbr_pos(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
		return ;
	current = head;
	while (current != NULL)
	{
		current->nbr = current->pos;
		current = current->next;
	}
}

void	tail_to_head(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a->next != NULL)
		a = a->next;
	a->next = tmp;
	tmp->previous = a;
}
