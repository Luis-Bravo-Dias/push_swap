/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:51:10 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/16 16:55:20 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_lower(t_stack *stka, int test)
{
	while (stka)
	{
		if (stka->nb < test)
			return (ERROR);
		stka = stka->next;
	}
	return (NICE);
}

t_steps	steper_b(int size, int pos)
{
	t_steps	b;

	b.opt = DOWN;
	if (pos <= size / 2 + size % 2)
	{
		b.moves = pos - 1;
		b.opt = UP;
	}
	else
		b.moves = size - pos + 1;
	return (b);
}

t_steps	steper_a(t_stack *stka, int test)
{
	t_stack	*tmp;
	int		counter;
	t_steps	valors;

	tmp = stka;
	counter = 1;
	if (is_lower(stka, test))
		return (steper_b(stk_size(stka), find_less(stka)));
	while (tmp->next)
	{
		if (test > tmp->nb && test < tmp->next->nb)
			return (steper_b(stk_size(stka), counter + 1));
		counter++;
		tmp = tmp->next;
	}
	valors.moves = 0;
	valors.opt = 0;
	return (valors);
}

t_moves	steps(t_stack *stka, t_stack *stkb, int test, int counter)
{
	t_moves	moves;

	moves.a = steper_a(stka, test);
	moves.b = steper_b(stk_size(stkb), counter);
	return (moves);
}

void	best_move(t_stack **stka, t_stack **stkb)
{
	t_moves	best;
	t_moves	test;
	t_stack	*tmp;
	int		counter;

	counter = 1;
	tmp = *stkb;
	best = steps(*stka, *stkb, tmp->nb, counter);
	while (tmp)
	{	
		test = steps(*stka, *stkb, tmp->nb, counter);
		if (test.a.moves + test.b.moves < best.a.moves + best.b.moves)
		{
			best = test;
		}
		counter++;
		tmp = tmp->next;
	}
	do_best(stka, stkb, best);
}
