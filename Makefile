# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 07:39:21 by sbahaddi          #+#    #+#              #
#    Updated: 2019/01/22 23:11:21 by sbahaddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./fdf

SRCS = src/calc_points.c \
	   src/converts.c \
	   src/draw.c \
	   src/events_key.c \
	   src/main.c \
	   src/projection.c \
	   src/read_file.c \
	   src/struct_fun.c

LIBFTSRC = libft/

LIBFTLIB = libft/libft.a

all : $(NAME)

$(NAME) :
	@make -C $(LIBFTSRC)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) $(LIBFTLIB) -l mlx -framework OpenGL -framework AppKit

clean :
	@/bin/rm -f *.o
	@/bin/rm -f $(LIBFTSRC)*.o

fclean : clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIBFTLIB)

re : fclean all
	@make -C $(LIBFTSRC) re
