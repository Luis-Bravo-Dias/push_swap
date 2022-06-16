/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:46 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/07 12:33:32 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swaper(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap(t_stack **stacka, t_stack **stackb, char opt)
{
	if (opt == 'a')
	{
		swaper(stacka);
		write(1, "sa\n", 3);
	}
	else if (opt == 'b')
	{
		swaper(stackb);
		write(1, "sb\n", 3);
	}
	else if (opt == 'x')
	{
		swaper(stacka);
		swaper(stackb);
		write(1, "ss\n", 3);
	}
	else
		return ;
}

void	pusher(t_stack **origin, t_stack **dest)
{
	t_stack	*tmp;

	if (*origin == NULL)
		return ;
	tmp = *origin;
	*origin = (*origin)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	push(t_stack **stacka, t_stack **stackb, char opt)
{
	if (opt == 'a')
	{
		pusher(stackb, stacka);
		write(1, "pa\n", 3);
	}
	else if (opt == 'b')
	{
		pusher(stacka, stackb);
		write(1, "pb\n", 3);
	}
	else
		return ;
}
