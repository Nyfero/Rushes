# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 14:40:54 by gsap              #+#    #+#              #
#    Updated: 2022/01/09 21:21:56 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

NAME = faketest

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

BAD_M_DIR = bad_malloc

BUS_E_DIR = bus_error

ERR_DIR = error

NO_ERR_DIR = no_error

FUNC_DIR = functions

LIBUNIT_DIR = ../framework

LIBFT_DIR = ../libft

LIBUNIT = $(LIBUNIT_DIR)/libunit.a

LIBFT = $(LIBFT_DIR)/libft.a

INC = $(LIBUNIT_DIR)/inc/libunit.h

SRCS = $(addprefix $(BAD_M_DIR)/, 00_bad_malloc_launcher.c 01_bad_malloc_segfault.c) \
	$(addprefix $(BUS_E_DIR)/, 00_bus_error_launcher.c 01_bus_error_sigbus.c) \
	$(addprefix $(ERR_DIR)/, 00_error_launcher.c 01_error_test.c) \
	$(addprefix $(NO_ERR_DIR)/, 00_no_error_launcher.c 01_no_error_test.c) \
	$(addprefix $(FUNC_DIR)/, bad_malloc.c bus_error.c error.c no_error.c) \
	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

test: all
	@./$(NAME)

.c.o:
	@ ${CC} ${CFLAGS} -I $(INC) -c $< -o ${<:.c=.o}

$(NAME): $(LIBFT) $(LIBUNIT) $(OBJS) $(INC)
	@ echo "$(BLUE)\n		*** Make $(NAME) ***\n$(END)"
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBUNIT)
	@ echo "$(GREEN)\n		---$(NAME) created ---\n$(END)"

$(LIBUNIT):
	@ echo "$(BLUE)\n		*** Make Libunit ***\n$(END)"
	@ make -C $(LIBUNIT_DIR)

$(LIBFT):
	@ echo "$(BLUE)\n		*** Make Libft ***\n$(END)"
	@ make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	@ make clean -C $(LIBUNIT_DIR)
	@ make clean -C $(LIBFT_DIR)
	@ echo "$(PURPLE)\n		*** Clean objects ***\n$(END)"

fclean: clean
	$(RM) $(NAME)
	@ make fclean -C $(LIBUNIT_DIR)
	@ make fclean -C $(LIBFT_DIR)
	@ echo "$(RED)\n		*** Remove $(NAME) ***\n$(END)"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus test
