# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 19:49:45 by bbeldame          #+#    #+#              #
#    Updated: 2017/08/24 17:18:58 by msakwins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

INC = includes

SRC_PATH = srcs
OBJ_PATH = obj
LIBFT_PATH = libft
LIBFTA = libft.a
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFTA))

SRC_NAME = search.c \
	ft_putwchar.c \
	ft_putwstr.c \
	ft_printf.c \
	ft_putnstr.c \
	get_intlen.c \
	handle_s.c \
	handle_d.c \
	handle_o.c \
	handle_x.c \
	handle_b.c \
	handle_p.c \
	handle_u.c \
	handle_c.c \
	ft_countbits.c \
	lenght_mod.c \
	handle_mod.c \
	apply_flags.c \
	utils.c \
	handle_bd.c

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)--------ft_printf compiled--------$(NC)"

clean:
	@make clean -C $(LIBFT_PATH)
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)---ft_printf removed completely---$(NC)"

re: fclean all
