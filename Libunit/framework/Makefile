# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2022/01/09 15:29:34 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Linux's Color
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

NAME = libunit.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

RM = rm -rf

SRCS_PATH = srcs

SRCS = $(addprefix $(SRCS_PATH)/,display.c list.c ft_error.c ft_utils.c)

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.c,	$(OBJS_PATH)%.o,	$(SRCS))

INC = inc/libunit.h

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(INC)
	@ $(AR) $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ echo "$(GREEN)\n		--- $(NAME) created ---\n$(END)"

$(OBJS_PATH):
	@ mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	@ $(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	@ $(RM) $(OBJS_PATH)
	@ echo "$(PURPLE)\n		*** Clean objs in $(NAME) ***\n$(END)"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "$(RED)\n		*** Clean $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re
