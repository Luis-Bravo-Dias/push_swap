/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:39:02 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/02 12:40:36 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotater(t_stack	**stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

void	rotate(t_stack **stacka, t_stack **stackb, char opt)
{
	if (opt == 'a')
	{
		rotater(stacka);
		write(1, "ra\n", 3);
	}
	else if (opt == 'b')
	{
		rotater(stackb);
		write(1, "rb\n", 3);
	}
	else if (opt == 'x')
	{
		rotater(stacka);
		rotater(stackb);
		write(1, "rr\n", 3);
	}
	else
		return ;
}

void	r_rotater(t_stack	**stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	while (tmp->next->nb != (*stack)->nb)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	r_rotate(t_stack **stacka, t_stack **stackb, char opt)
{
	if (opt == 'a')
	{
		r_rotater(stacka);
		write(1, "rra\n", 4);
	}
	else if (opt == 'b')
	{
		r_rotater(stackb);
		write(1, "rrb\n", 4);
	}
	else if (opt == 'x')
	{
		r_rotater(stacka);
		r_rotater(stackb);
		write(1, "rrr\n", 4);
	}
	else
		return ;
}
