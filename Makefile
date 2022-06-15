# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakefileProgram                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:38 by ailopez-          #+#    #+#              #
#    Updated: 2022/06/03 11:31:48 by aitoraudi        ###   ########.fr        #
#    Updated: 2022/05/24 00:35:24 by aitorlope        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#Variables

NAME		= a.out
INCLUDE		= inc
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra -D BUFFER_SIZE=4 -MMD -I 
RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	main get_next_line get_next_line_utils


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:	makelibs
	@$(MAKE)	$(NAME)

makelibs:	
			@$(MAKE) -C $(LIBFT)
			
-include 	${DEPS}
$(NAME):	$(OBJ) ${LIBFT}/libft.a $(INCLUDE)/get_next_line.h
			make -C $(LIBFT)
			${CC} ${OBJ} ${LIBFT}/${LIBFT}.a -o ${NAME}
			@echo "$(MAGENTA)${CC} ${OBJ} ${LIBFT}/${LIBFT}.a -o ${NAME} $(DEF_COLOR)"
			@echo "$(GREEN)GetNextLine Ready!$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(CYAN)GetNextLine object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)GetNextLine executable files cleaned!$(DEF_COLOR)"
			$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"
			${RM} bonus

re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for GetNextLine!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

