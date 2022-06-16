/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:30:51 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/16 17:00:44 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_less(t_stack *stack)
{
	int		less;
	int		pos;
	int		counter;

	less = stack->nb;
	counter = 1;
	pos = 1;
	while (stack)
	{
		if (stack->nb < less)
		{
			less = stack->nb;
			pos = counter;
		}
		stack = stack->next;
		counter++;
	}
	return (pos);
}

void	rotate_push(int size, t_stack **stka, t_stack **stkb, int pos)
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
	push(stka, stkb, 'b');
}

int	*sorter(int *list, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (list[i] > list[i + 1])
		{
			tmp = list[i];
			list [i] = list [i + 1];
			list [i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (list);
}

int	*get_sorted(int size, t_stack *stack)
{
	int	*list;
	int	i;

	i = 0;
	list = malloc(sizeof(int) * size);
	while (stack)
	{
		list[i] = stack->nb;
		i++;
		stack = stack->next;
	}
	return (sorter(list, size));
}

int	stk_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
