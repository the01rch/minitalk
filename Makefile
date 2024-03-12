# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 19:41:59 by redrouic          #+#    #+#              #
#    Updated: 2024/03/12 17:52:14 by redrouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1	=	src/server.c\
			src/util.c

SRC2	=	src/client.c\
			src/util.c

CC	=	gcc

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

NAME1	=	server

NAME2	=	client

CFLAGS	+=	-Wall -Wextra -Werror -g3

RM	=	rm -rf

all: $(NAME2) $(NAME1)
	
$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ2)
	$(RM) $(OBJ1)

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
