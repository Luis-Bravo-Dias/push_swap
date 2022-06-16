/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:28:05 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/16 16:54:54 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	go_chunks(t_chunks *chunks, int nbr_chunks)
{
	chunks->min -= chunks->c_size;
	chunks->max -= chunks->c_size;
	chunks->min2 += chunks->c_size;
	if (chunks->max2 + chunks->c_size >= chunks->c_size * nbr_chunks - 1)
	{
		chunks->max2 = chunks->l_size - 4;
		if (chunks->last != 1)
			chunks->last = 2;
	}
	else
		chunks->max2 += chunks->c_size;
	chunks->left = chunks->max - chunks->min + chunks->max2 - chunks->min2 + 2;
}

void	chunker(t_chunks *chunks, t_stack **stka,
	t_stack **stkb, int nbr_chunks)
{
	while (chunks->last != 1)
	{
		if (chunks->last == 2)
			chunks->last = 1;
		while (chunks->left)
		{
			if ((*stka)->nb >= chunks->list[chunks->min]
				&& (*stka)->nb <= chunks->list[chunks->max])
			{
				push(stka, stkb, 'b');
				chunks->left--;
			}
			else if ((*stka)->nb >= chunks->list[chunks->min2]
				&& (*stka)->nb <= chunks->list[chunks->max2])
			{
				push(stka, stkb, 'b');
				rotate(stka, stkb, 'b');
				chunks->left--;
			}
			rotate(stka, stkb, 'a');
		}
		go_chunks(chunks, nbr_chunks);
	}
}

void	init_chunks(int size, t_stack **stka, t_stack **stkb, int nbr_chunks)
{
	t_chunks	chunks;

	chunks.list = get_sorted(size, *stka);
	chunks.c_size = size / nbr_chunks;
	chunks.min = chunks.c_size * ((nbr_chunks / 2 + nbr_chunks % 2) - 1);
	chunks.max = chunks.min + chunks.c_size - 1;
	chunks.last = 0;
	chunks.l_size = size;
	if (nbr_chunks % 2 == 0)
	{
		chunks.max2 = chunks.max + chunks.c_size;
		chunks.min2 = chunks.min + chunks.c_size;
		chunks.left = (chunks.max - chunks.min + 1) * 2;
	}
	else
	{
		chunks.max2 = chunks.max;
		chunks.min2 = chunks.min;
		chunks.left = chunks.max - chunks.min + 1;
	}
	chunker(&chunks, stka, stkb, nbr_chunks);
	free(chunks.list);
}
