#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 16:54:54 by kpiacent          #+#    #+#              #
#    Updated: 2016/04/30 15:38:59 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = ft_ls
L_DIR = libft
F_DIR = src
H_DIR = src
FILES = $(F_DIR)/main.c $(F_DIR)/dir.c $(F_DIR)/file.c $(F_DIR)/sort.c \
$(F_DIR)/print.c $(F_DIR)/is.c $(F_DIR)/list.c $(F_DIR)/dispatch.c \
$(F_DIR)/get.c $(F_DIR)/get_2.c $(F_DIR)/mode.c $(F_DIR)/set.c $(F_DIR)/files.c \
$(F_DIR)/filter.c

TMP = Makefile~  $(F_DIR)/$(NAME).h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
		@cd $(L_DIR) && $(MAKE)
		@CC -o $(NAME) $(FLAGS) $(FILES) -I $(L_DIR) -L $(L_DIR) -lft
		@echo "Complilation: \t\t\tDONE!"

clean :
		@rm -f $(TMP)
		@cd $(L_DIR) && $(MAKE) $@
		@echo "Cleaning: \t\t\tDONE!"

fclean : clean
		@rm -f $(NAME)
		@cd $(L_DIR) && $(MAKE) $@
		@echo "Remove the exec: \t\tDONE!"
test :
	./$(NAME)

re : fclean all
