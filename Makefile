# Nome do executável
NAME = push_swap

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR)

# Diretórios
SRCDIR = .
LIBFTDIR = libft

# Arquivos fonte e objetos
SRCS = $(SRCDIR)/push_swap.c \
       $(SRCDIR)/stack_utils.c \
	   $(SRCDIR)/push_swap_validation.c \
	   $(SRCDIR)/stack.c \
	   $(SRCDIR)/stack_sort.c \
	   $(SRCDIR)/stack_operations.c \

OBJS = $(SRCS:.c=.o)

# Regras
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFTDIR) -lft
	@echo "Compilação concluída!"

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado $<"

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFTDIR)
	@echo "Arquivos objeto removidos!"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@echo "Executável removido!"

re: fclean all

.PHONY: all clean fclean re
