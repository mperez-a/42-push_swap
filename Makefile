# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 17:25:07 by mperez-a          #+#    #+#              #
#    Updated: 2023/05/10 10:02:55 by mperez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------VARIABLES----------------------------------#
NAME = push_swap
CFLAGS = -Wextra -Werror -Wall
SRC = push_swap.c check_input.c utils.c lst_utils.c sort_small.c \
		swap_mov.c rotate_mov.c reverse_rotate_mov.c push_mov.c \
		sort_big.c sort_nums.c put_index.c ft_free.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
RM = rm -f
LIBS = libft/libft.a ft_printf/libftprintf.a

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
%.o : %.c $(libs) Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all :
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(MAKE) $(NAME)	

$(NAME):: $(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $@
	@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"


-include $(DEP)

clean :
	@$(RM) $(OBJ) $(DEP)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@echo "$(RED)Files deleted successfully!$(DEF_COLOR)"

fclean : clean
	@$(RM) $(NAME) $(LIBS)

re : fclean all
	@echo "$(GREEN)Everything have been recompiled!$(DEF_COLOR)"

.PHONY: all clean fclean re
