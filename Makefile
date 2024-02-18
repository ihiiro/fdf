# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 09:46:00 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/02/18 15:53:42 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
HEADERS = get_next_line/get_next_line.h fdf.h
SOURCES = main.c exitf.c rows_cols.c data.c satoi.c draw.c bresenhams.c \
		  isometric.c exits.c controls.c
GET_NEXT_LINE_BONUS = _bonus/get_next_line/get_next_line.c _bonus/get_next_line/get_next_line_utils.c
HEADERS_BONUS = _bonus/get_next_line/get_next_line.h _bonus/fdf_bonus.h
SOURCES_BONUS = _bonus/main_bonus.c _bonus/exitf_bonus.c _bonus/rows_cols_bonus.c _bonus/data_bonus.c _bonus/satoi_bonus.c _bonus/draw_bonus.c _bonus/bresenhams_bonus.c \
		  _bonus/isometric_bonus.c _bonus/controls_bonus.c _bonus/transform_bonus.c _bonus/actions/rotate_bonus.c _bonus/actions/translate_bonus.c \
		  _bonus/actions/zoom_bonus.c _bonus/exits_bonus.c _bonus/blackhole_event_horizon_bonus.c
GRAPHICS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SOURCES) $(GET_NEXT_LINE) $(HEADERS) #add cflags later and remove -g
	cc -g  $(SOURCES) $(GET_NEXT_LINE) $(GRAPHICS) -o $@

bonus: $(SOURCES_BONUS) $(GET_NEXT_LINE_BONUS) $(HEADERS_BONUS) #add cflags later and remove -g
	cc -g  $(SOURCES_BONUS) $(GET_NEXT_LINE_BONUS) $(GRAPHICS) -o $(NAME)

clean:
	rm -f fdf

fclean: clean

re: fclean all