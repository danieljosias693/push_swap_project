# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvemba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 17:39:28 by dvemba            #+#    #+#              #
#    Updated: 2024/10/02 17:39:30 by dvemba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nome do executavel.
NAME = push_swap

#Directorio actual.
DIR = .

#Compilador.
CC = gcc

LIBFT = libft
#Flags
FLGS = -Wall -Wextra -Werror -I$(LIBFT)

#Lista todos os arquivos fontes.
SRC = $(DIR)/push_swap_validation.c \
		$(DIR)/push_swap.c \
		$(DIR)/stack_operations.c \
		$(DIR)/stack_sort.c \
		$(DIR)/stack_utils.c \
		$(DIR)/stack.c \
		$(DIR)/push_swap_validation_second.c \
		$(DIR)/stack_operations_second.c \
		$(DIR)/stack_operations_third.c \
		$(DIR)/stack_sort_second.c \

#Lista todos arquivos objectos.
OBJ = $(SRC:.c=.o)

#Execucao principal.
all:	$(NAME)

$(NAME): 	$(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(FLGS) -o $@ $(OBJ) -L$(LIBFT) -lft
	@echo "Compilacao concluida!"

#Limpa os arquivos objectos.
clean: 
	$(MAKE) clean -C $(LIBFT)
	@rm -f $(OBJ)
	@echo "Arquivos objectos limpos."

#Limpa os arquivos objectos e o executavel.
fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo "Arquivos objectos e executavel limpos."

#recompila o projecto
re: fclean all

.PHONY: fclean clean re all
