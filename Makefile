# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 15:59:24 by abeaudui          #+#    #+#              #
#    Updated: 2023/05/17 16:00:37 by abeaudui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
AR = ar -rc
CFLAGS = -Wall -Wextra -Werror
MKFLAGS = --no-print-directory
DEPS = includes
SRCS = .
CLIENT = client
SERVER = server
PRINTF = ft_printf/libftprintf.a
SOURCE_S = server.c utils.c
SOURCE_C = client.c utils.c
OBJ_SERVER = $(SOURCE_S:%.c=%.o)
OBJ_CLIENT = $(SOURCE_C:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	@make $(MKFLAGS) -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(CLIENT) -I $(DEPS)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(SERVER) -I $(DEPS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	@make clean $(MKFLAGS) -C ft_printf
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) 

fclean: clean
	@make fclean $(MKFLAGS) -C ft_printf
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: re fclean all clean
