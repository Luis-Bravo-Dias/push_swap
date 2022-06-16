# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 10:59:02 by lleiria-          #+#    #+#              #
#    Updated: 2022/06/16 15:44:20 by lleiria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror 
RM			=	rm -f

NAME		=	push_swap

DEPS		=	libft/libft.a ft_printf/libftprintf.a
INCLUDE		=	 -I ft_printf/ft_printf.h -I libft/libft.h -I push_swap.h
SRCS_		=	main.c \
				swap_push.c \
				rotate.c \
				check_in.c \
				push_swap.c \
				utils.c \
				chunks.c \
				organize.c \
				do_best.c 

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

_OBJ		=	./obj/
_SRC		= 	./src/
OBJS		=	$(patsubst $(_SRC)%.c, $(_OBJ)%.o, $(SRCS))

all:		$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(DEPS) $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME) $(DEPS)

#bonus:		$(SRCS_B) $(OBJS_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -c

libft/libft.a:
	make libft.a -C libft
ft_printf/libftprintf.a:
	make libftprintf.a -C ft_printf

$(_OBJ):
	mkdir $@

clean:
	make clean -C ft_printf
	make clean -C libft
	$(RM) -r $(_OBJ)

fclean:	clean
	make fclean -C ft_printf
	make fclean -C libft
	$(RM) $(NAME)

re:	fclean all
