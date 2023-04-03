/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:54 by mperez-a          #+#    #+#             */
/*   Updated: 2023/03/24 15:17:42 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
// borrar
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	int				pos;
	int				index;
	struct s_stack	*next;
}				t_stack;

//utils
void			push_swap(int argc, char **args);
char			**copy_args(int argc, char **argv);
int				ft_numelements(t_stack **a);
int				ft_issorted(t_stack *a);
int				check_input(char **args);
long long int	ft_atol(char *str);
//void			ft_error(t_stack stack_a);
int				ft_isnum(char *str);
int				ft_isdup(char **args, int num, int elements);
int				ft_find_minor(t_stack **stack_a);
int				ft_find_biggest(t_stack **stack_a);
void			ft_update_position(t_stack **stack);
void			ft_put_index(t_stack **stack);

//lst utils
t_stack			*ft_newlst(int pos, int content);
t_stack			*ft_lastlst(t_stack *lst);
t_stack			*fill_stacka(t_stack *stack_a, int argc, char **args);
void			ft_addlst_back(t_stack **lst, t_stack *new);

//print
void			mostra(t_stack **a);

//moves
void			swap_mov(t_stack **stack);
void			ss_mov(t_stack **stack_a, t_stack **stack_b);
void			rotate_mov(t_stack **stack);
void			reverse_rotate_mov(t_stack **stack);
void			push_mov(t_stack **src, t_stack **dst);

//sorts
void			sort_small(t_stack **a, int elements);
void			sort_three(t_stack **stack);
void			sort_four(t_stack **a, t_stack **b);
void			sort_five(t_stack **a, t_stack **b);
void			sort_four_five(t_stack **a, t_stack **b, int elements);

//exec movements
void			swap(t_stack **stack, char c);
void			reverse_rotate(t_stack **stack, char c);
void			rotate(t_stack **stack, char c);
void			push(t_stack **src, t_stack **dst, char c);

#endif
