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
CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra -D BUFFER_SIZE=1000000
RM			= rm -f


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

SRC		=	main.c proyect/get_next_line.c proyect/get_next_line_utils.c
OBJS	=	$(SRC:%.c=%.o)

###

all:	
	@$(MAKE)	$(NAME)

			
$(NAME):	${OBJS} proyect/get_next_line.h
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "${CC} ${FLAGS} ${OBJS} -o ${NAME} $(DEF_COLOR)"
			@echo "$(GREEN)GetNextLine Ready!$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
clean:
			${RM} ${OBJS}
			@echo "$(CYAN)GetNextLine object files cleaned!$(DEF_COLOR)"

fclean:		clean
			${RM} ${NAME} 
			@echo "$(CYAN)GetNextLine executable files cleaned!$(DEF_COLOR)"	


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for GetNextLine!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

