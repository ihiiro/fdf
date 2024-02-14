# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 09:46:00 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/02/14 12:01:24 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
HEADERS = get_next_line/get_next_line.h fdf.h
SOURCES = main.c exitf.c rows_cols.c data.c satoi.c draw.c bresenhams.c isometric.c
GRAPHICS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SOURCES) $(GET_NEXT_LINE) $(HEADERS) #add cflags later and remove -g
	cc -g  $(SOURCES) $(GET_NEXT_LINE) $(GRAPHICS) -o $@

clean:
	rm -f fdf

fclean: clean

re: fclean all