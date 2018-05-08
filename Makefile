# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/08 10:40:29 by lprunier          #+#    #+#              #
#    Updated: 2018/05/08 10:40:32 by lprunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRC = 	src/ft_malloc.c\
		src/ft_realloc.c\
		src/alloc.c\
		src/create.c\
		src/place.c\
		src/print.c\
		src/show_alloc_mem.c\
		src/ft_free.c\
		src/puts.c\

OBJ = 	$(SRC:.c=.o)

NAME = 	libft_malloc.so

CFLAGS = -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g $(CFLAGS) $(OBJ) -fPIC -shared -o libft_malloc_$(HOSTTYPE).so
	ln -sf libft_malloc_$(HOSTTYPE).so libft_malloc.so

%.o: %.c
	gcc -g $(CFLAGS) -c $< -I./include  -o $@ 

clean:
	echo "\033[1;31m" "DELETE FILES MALLOC" "\033[0m"
	rm -f $(OBJ)

fclean: clean
	echo "\033[1;31m" "DELETE MALLOC.SO" "\033[0m"
	rm -f libft_malloc.so
	rm -f libft_malloc_$(HOSTTYPE).so

re: fclean all
