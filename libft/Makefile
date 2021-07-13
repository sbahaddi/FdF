# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbahaddi <said.bahaddi@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 11:53:15 by sbahaddi          #+#    #+#              #
#    Updated: 2019/01/22 23:02:07 by sbahaddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES_C = *.c 

SOURCES_O = *.o 

all: $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SOURCES_C)
	@ar rc $(NAME) $(SOURCES_O)
	@ranlib $(NAME)

clean :
	@/bin/rm -f $(SOURCES_O)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
