# Colors linux
#GREY = \e[90m
#RED = \e[91m
#GREEN = \e[92m
#YELLOW = \e[93m
#BLUE = \e[34m
#PURPLE = \e[95m
#CYAN = \e[96m
#END = \e[39m

NAME = hotrace

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -flto

RM = rm -rf

SRCS_PATH = srcs

SRCS = $(addprefix $(SRCS_PATH)/,hotrace.c ft_str_utils.c ft_create.c ft_hash.c)

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.c,	$(OBJS_PATH)%.o, $(SRCS))

INC = inc/

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	@ echo "\n		*** Make $(NAME) ***\n"
	@ $(CC) $(CFLAGS) $(OBJS_PATH)/*.o -o $(NAME)
	@ echo "\n		---$(NAME) created ---\n"

$(OBJS_PATH):
	@ mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)/$(NAME).h
	@ $(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	@ $(RM) $(OBJS_PATH)
	@ echo "\n		*** Clean objects ***\n"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "\n		*** Remove $(NAME) ***\n"

re: fclean all

.PHONY: all clean fclean re