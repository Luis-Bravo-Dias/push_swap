/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:22:15 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/16 16:58:48 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_org(t_stack **stka)
{
	t_stack	*tmp;

	tmp = *stka;
	while (tmp->next != NULL)
	{
		if (tmp->nb > tmp->next->nb)
			return (ERROR);
		tmp = tmp->next;
	}
	return (NICE);
}

void	do_2(t_stack **stka, t_stack **stkb)
{
	if ((*stka)->nb > (*stka)->next->nb)
		swap(stka, stkb, 'a');
}

void	do_3(t_stack **stka, t_stack **stkb)
{
	if ((*stka)->nb < (*stka)->next->nb
		&& (*stka)->next->nb < (*stka)->next->next->nb)
		return ;
	if ((*stka)->nb < (*stka)->next->next->nb)
		swap(stka, stkb, 'a');
	if ((*stka)->nb > (*stka)->next->nb
		&& (*stka)->next->nb > (*stka)->next->next->nb)
		swap(stka, stkb, 'a');
	if ((*stka)->next->nb > (*stka)->next->next->nb
		&& (*stka)->nb > (*stka)->next->next->nb)
		r_rotate(stka, stkb, 'a');
	if ((*stka)->nb < (*stka)->next->nb
		&& (*stka)->next->nb > (*stka)->next->next->nb)
		rotate(stka, stkb, 'a');
	if ((*stka)->nb > (*stka)->next->nb
		&& (*stka)->next->nb < (*stka)->next->next->nb)
		rotate(stka, stkb, 'a');
}

void	do_4_5(int total, t_stack **stka, t_stack **stkb)
{
	while (total > 3)
	{
		rotate_push(total, stka, stkb, find_less(*stka));
		total--;
	}
	do_3(stka, stkb);
	while (*stkb)
		push(stka, stkb, 'a');
}

void	push_swap(int ac, t_stack **stka, t_stack **stkb)
{
	if (is_org(stka))
		return ;
	else if (ac == 3)
		do_2(stka, stkb);
	else if (ac == 4)
		do_3(stka, stkb);
	else if (ac == 5 || ac == 6)
		do_4_5(ac - 1, stka, stkb);
	else
	{
		init_chunks(ac - 1, stka, stkb, 4);
		do_3(stka, stkb);
		while (*stkb)
			best_move(stka, stkb);
		final_correction(ac - 1, stka, stkb, find_less(*stka));
	}
}
