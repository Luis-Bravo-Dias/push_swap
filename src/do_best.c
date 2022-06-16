/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:51:19 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/16 15:43:45 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_dif(t_stack **stka, t_stack **stkb, t_moves best)
{
	while (best.a.moves > 0 && best.a.opt == UP)
	{
		rotate(stka, stkb, 'a');
		best.a.moves--;
	}
	while (best.a.moves > 0 && best.a.opt == DOWN)
	{
		r_rotate(stka, stkb, 'a');
		best.a.moves--;
	}
	while (best.b.moves > 0 && best.b.opt == UP)
	{
		rotate(stka, stkb, 'b');
		best.b.moves--;
	}
	while (best.b.moves > 0 && best.b.opt == DOWN)
	{
		r_rotate(stka, stkb, 'b');
		best.b.moves--;
	}
}

void	is_equal_up(t_stack **stka, t_stack **stkb, t_moves best)
{
	while (best.a.moves > 0 && best.b.moves > 0)
	{
		rotate(stka, stkb, 'x');
		best.a.moves--;
		best.b.moves--;
	}
	while (best.a.moves > 0)
	{
		rotate(stka, stkb, 'a');
		best.a.moves--;
	}
	while (best.b.moves > 0)
	{
		rotate(stka, stkb, 'b');
		best.b.moves--;
	}
}

void	is_equal_down(t_stack **stka, t_stack **stkb, t_moves best)
{
	while (best.a.moves > 0 && best.b.moves > 0)
	{
		r_rotate(stka, stkb, 'x');
		best.a.moves--;
		best.b.moves--;
	}
	while (best.a.moves > 0)
	{
		r_rotate(stka, stkb, 'a');
		best.a.moves--;
	}
	while (best.b.moves > 0)
	{
		r_rotate(stka, stkb, 'b');
		best.b.moves--;
	}
}

void	final_correction(int size, t_stack **stka, t_stack **stkb, int pos)
{
	int	moves;
	int	opt;

	opt = 1;
	if (pos <= size / 2 + size % 2)
	{
		moves = pos - 1;
		opt = 0;
	}
	else
		moves = size - pos + 1;
	while (moves)
	{
		if (opt == 0)
			rotate(stka, stkb, 'a');
		else
			r_rotate(stka, stkb, 'a');
		moves--;
	}
}

void	do_best(t_stack **stka, t_stack **stkb, t_moves best)
{
	if (best.a.opt == UP && best.b.opt == UP)
		is_equal_up(stka, stkb, best);
	else if (best.a.opt == DOWN && best.b.opt == DOWN)
		is_equal_down(stka, stkb, best);
	else
		is_dif(stka, stkb, best);
	push(stka, stkb, 'a');
}
