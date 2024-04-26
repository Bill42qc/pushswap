/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:52:27 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 21:57:45 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bucket_completed(t_stack **a, int count, int lst_size, int divisor)
{
	t_stack	*tmp;

	tmp = (*a);
	while (count)
	{
		if ((tmp)->nbr >= (lst_size - (lst_size / divisor))
			|| ((tmp)->nbr <= (lst_size / divisor)))
			return (1);
		tmp = tmp->next;
		count--;
	}
	return (0);
}

//try to free the stack
void	free_stack(t_stack *head)
{
	t_stack	*current;

	if (!head)
		return ;
	head->previous->next = NULL;
	while (head != NULL)
	{
		current = head;
		head = head->next;
		if (current != NULL)
			free(current);
	}
}

void	release(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check_arg(ac, av);
	a = init_list(ac, av);
	if (a == NULL)
		print_error();
	sort(&a, &b);
	free_stack(a);
	free_stack(b);
}
