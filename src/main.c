/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:14:51 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/16 16:57:12 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*void	print_stack(t_stack *stka, t_stack *stkb)
{
	t_stack	*ptr;

	ptr = stka;
	ft_printf("_______________STACK_A_______________\n");
	if (!ptr)
		ft_printf("\n\n                EMPTY\n");
	else
		ft_printf("\n\n");
	while (ptr)
	{
		ft_printf("                  %d\n", ptr->nb);
		ptr = ptr->next;
	}
	ft_printf("\n\n");
	ptr = stkb;
	ft_printf("_______________STACK_B_______________\n");
	if (!ptr)
		ft_printf("\n\n                EMPTY\n");
	else
		ft_printf("\n\n");
	while (ptr)
	{
		ft_printf("                  %d\n", ptr->nb);
		ptr = ptr->next;
	}
	ft_printf("\n_____________________________________\n");
}
*/
void	print_errors(char *message)
{
	ft_printf("%s", message);
	exit(1);
}

t_stack	*new_node(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **stack, t_stack *new)
{
	t_stack	*ptr;

	ptr = *stack;
	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	if (!ptr)
		ptr = new;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

void	stk_clear(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack)
		return ;
	while (stack && *stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stka;
	t_stack	*stkb;
	int		i;

	stka = NULL;
	i = 1;
	if (!check_in(ac, av))
		print_errors("Error\n");
	while (i < ac)
	{
		add_to_stack(&stka, new_node(ft_atoi(av[i])));
		i++;
	}
	stkb = NULL;
	push_swap(ac, &stka, &stkb);
	stk_clear(&stka);
}
