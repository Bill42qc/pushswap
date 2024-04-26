/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:36 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 22:59:37 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

//message erreur

# define E_ARGS_NUM "Error\n"

//definition des structures utilisé dans les .c

typedef struct s_stack
{
	int				nbr;
	int				pos;

	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

//function

void				print_error(void);
void				release(void **tab);
int					bucket_completed(t_stack **a, int count, int lst_size,
						int divisor);

//check arg functions//
void				check_arg(int ac, char **av);
void				many_arg(int ac, char **av);
void				one_arg(char *av);
int					ft_isdigit_or_space(int c);
void				fake_minus_check(char *str);
void				check_no_double_string(char **av);

//create list function
t_stack				*init_list(int ac, char **av);
t_stack				*create_list_2ac(char *av);
void				create_list_2ac2(int i, int nbr, char **split,
						t_stack *head);
t_stack				*create_list(int ac, char **av);
t_stack				*create_node(int nbr, int pos);
t_stack				*init_b(t_stack *a);

//create_list utils
int					check_duplicate(t_stack *head, int nbr);
void				find_pos(t_stack *head);
void				swap_nbr_pos(t_stack *head);
void				tail_to_head(t_stack *a);

//INSTRUCTION

//swap

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

//push
void				pb(t_stack **a, t_stack **b, int print_id);
void				pb2(t_stack **b, t_stack *tmp, int print_id);
void				pa(t_stack **a, t_stack **b);

//rotate
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

//sort

void				sort(t_stack **a, t_stack **b);
void				three_sort(t_stack **a);
void				four_sort(t_stack **a, t_stack **b);
void				five_sort(t_stack **a, t_stack **b);
void				five_sort2(t_stack **a, t_stack **b, int smallest_pos);
void				big_sort(t_stack **a, t_stack **b);
void				big_int_sort(t_stack **a, t_stack **b);

//sort utils
void				check_if_sorted(t_stack *a);
int					ft_lstsize_chain(t_stack *lst);
int					lst_smallest_element(t_stack **a);
void				small_sort_combo(t_stack **a, t_stack **b);
void				ra_or_rra(t_stack **a, int lst_size, int smallest_int);
int					find_pos_sort(t_stack *head, int nbr);
void				box_sort(t_stack **a, t_stack **b);
void				box_utils(t_stack **a, t_stack **b, int lst_size,
						int divisor);

//free
void				free_stack(t_stack *head);

#endif
