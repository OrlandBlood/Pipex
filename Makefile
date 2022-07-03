NAME	=	pipex

SRCS	=	main.c ft_find_path.c ft_split.c ft_strjoin.c ft_strnstr.c ft_strlen.c ft_strcmp.c ft_get_next_line.c ft_strnjoin.c ft_here_doc.c

HEADER	=	pipex.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o 	:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@rm -f $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all
