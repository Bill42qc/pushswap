/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:31:57 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 21:56:30 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_list(int ac, char **av)
{
	t_stack	*head;

	head = NULL;
	if (ac > 2)
	{
		head = create_list(ac, av);
		find_pos(head);
		swap_nbr_pos(head);
		tail_to_head(head);
		return (head);
	}
	else if (ac == 2)
	{
		head = create_list_2ac(av[1]);
		find_pos(head);
		swap_nbr_pos(head);
		tail_to_head(head);
		return (head);
	}
	else
	{
		print_error();
		return (NULL);
	}
}

t_stack	*create_list(int ac, char **av)
{
	t_stack	*head;
	t_stack	*current;
	int		i;
	int		nbr;

	head = create_node(ft_atoi(av[1]), 1);
	if (head == NULL)
	{
		return (NULL);
	}
	current = head;
	i = 2;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (check_duplicate(head, nbr) == 1)
			print_error();
		current->next = create_node(nbr, i);
		current->next->previous = current;
		current = current->next;
		i++;
	}
	return (head);
}

t_stack	*create_list_2ac(char *av)
{
	t_stack	*head;
	int		i;
	int		nbr;
	char	**split;

	nbr = 0;
	split = ft_split(av, ' ');
	head = create_node(ft_atoi(split[0]), 1);
	if (head == NULL)
		return (NULL);
	i = 1;
	create_list_2ac2(i, nbr, split, head);
	release((void **)split);
	return (head);
}

void	create_list_2ac2(int i, int nbr, char **split, t_stack *head)
{
	int		j;
	t_stack	*current;

	j = 2;
	current = head;
	while (split[i])
	{
		nbr = ft_atoi(split[i]);
		if (check_duplicate(head, nbr) == 1)
			print_error();
		current->next = create_node(nbr, j);
		current->next->previous = current;
		current = current->next;
		i++;
		j++;
	}
}
