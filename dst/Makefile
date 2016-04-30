#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 16:54:54 by kpiacent          #+#    #+#              #
#    Updated: 2016/04/28 18:41:08 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -g -Wall -Wextra -Werror
NAME = ft_ls
L_DIR = libft
F_DIR = src
H_DIR = src
FILES = $(F_DIR)/main.c $(F_DIR)/dir.c $(F_DIR)/file.c

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