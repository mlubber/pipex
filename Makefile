NAME	= pipex

INC		= -I ./include

CC		= gcc

CFLAGS	= -Werror -Wall -Wextra -fsanitize=address

RM		= rm -rf

SRCS	= $(shell find ./sources -iname "*.c")

OBJS	:= ${SRCS:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC) && printf "Compiling: $(notdir $<)\n"

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

all : $(NAME)

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) $(OBJS)

re : fclean all
