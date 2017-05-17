# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 19:49:45 by msakwins          #+#    #+#              #
#    Updated: 2017/05/17 22:27:06 by bbeldame         ###   ########.fr        #
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
	ft_putllnbr.c \
	ft_printf.c \
	ft_putnstr.c \
	putnbr_base.c \
	itoa_base.c \
	get_intlen.c \
	handle_s.c \
	handle_d.c \
	handle_o.c \
	handle_x.c \
	handle_p.c \
	handle_u.c \
	handle_w.c \
	ft_countbits.c \
	lenght_mod.c \
	handle_mod.c

#SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH)
	echo "cc"
	gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	echo "slt"
	make -C $(LIBFT_PATH)
	cp $(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	/bin/rm -rf $(NAME)

re: fclean all
