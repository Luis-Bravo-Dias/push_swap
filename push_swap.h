/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:17:28 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/16 16:57:46 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define ERROR 0
# define NICE 1
# define UP 0
# define DOWN 1
//#define malloc(x)(void *)0

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunks
{
	int	*list;
	int	max;
	int	min;
	int	max2;
	int	min2;
	int	last;
	int	c_size;
	int	left;
	int	l_size;
}	t_chunks;

typedef struct s_steps
{
	int	moves;
	int	opt;
}	t_steps;

typedef struct s_moves
{
	t_steps	a;
	t_steps	b;
}	t_moves;

//main
void	print_errors(char *message);
t_stack	*new_node(int nb);
void	print_stack(t_stack *stka, t_stack *stkb);
void	add_to_stack(t_stack **stack, t_stack *new);
void	stk_clear(t_stack **stack);
//swap_push
void	swaper(t_stack **stack);
void	swap(t_stack **stacka, t_stack **stackb, char opt);
void	pusher(t_stack **origin, t_stack **dest);
void	push(t_stack **stacka, t_stack **stackb, char opt);
//rotate
void	rotater(t_stack	**stack);
void	rotate(t_stack **stacka, t_stack **stackb, char opt);
void	r_rotater(t_stack	**stack);
void	r_rotate(t_stack **stacka, t_stack **stackb, char opt);
//check_in
int		is_nbr(char *str);
int		is_rep(int ac, char **av);
int		limits(int ac, char **av);
int		one_signal(int ac, char **av);
int		check_in(int ac, char **av);
//push_swap
int		is_org(t_stack **stka);
void	do_2(t_stack **stka, t_stack **stkb);
void	do_3(t_stack **stka, t_stack **stkb);
void	do_4_5(int total, t_stack **stka, t_stack **stkb);
void	push_swap(int ac, t_stack **stka, t_stack **stkb);
//utils.c
int		find_less(t_stack *stack);
void	rotate_push(int size, t_stack **stka, t_stack **stkb, int pos);
int		*sorter(int *list, int size);
int		*get_sorted(int size, t_stack *stack);
int		stk_size(t_stack *stack);
//chunks.c
void	go_chunks(t_chunks *chunks, int nbr_chunks);
void	chunker(t_chunks *chunks, t_stack **stka,
			t_stack **stkb, int nbr_chunks);
void	init_chunks(int size, t_stack **stka, t_stack **stkb, int nbr_chunks);
//organize.c
int		is_lower(t_stack *stka, int test);
t_steps	steper_b(int size, int pos);
t_steps	steper_a(t_stack *stka, int test);
t_moves	steps(t_stack *stka, t_stack *stkb, int test, int counter);
void	best_move(t_stack **stka, t_stack **stkb);
//do_best.c
void	is_dif(t_stack **stka, t_stack **stkb, t_moves best);
void	is_equal_up(t_stack **stka, t_stack **stkb, t_moves best);
void	is_equal_down(t_stack **stka, t_stack **stkb, t_moves best);
void	final_correction(int size, t_stack **stka, t_stack **stkb, int pos);
void	do_best(t_stack **stka, t_stack **stkb, t_moves best);

#endif