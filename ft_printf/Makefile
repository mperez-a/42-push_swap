# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 17:25:07 by mperez-a          #+#    #+#              #
#    Updated: 2023/01/29 13:17:08 by mperez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------VARIABLES----------------------------------#
CFLAGS = -Wextra -Werror -Wall
NAME = libftprintf.a
HEADER = ft_printf.h
SRC = ft_printf.c ft_print_str.c ft_print_nbr.c ft_print_nbr.c ft_print_ptr.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

#-------------------------------------COLORS-----------------------------------#

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#-------------------------------------RULES------------------------------------#
%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@ar crs $(NAME) $(OBJ)

-include $(DEP)

clean :
	@rm -f $(OBJ) $(DEP)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
