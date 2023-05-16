#! Colors
RESET = \033[0m       # Text Reset
BLACK = \033[1;30m       # Black
RED = \033[1;31m         # Red
GREEN = \033[1;32m       # Green
YELLOW = \033[1;33m      # Yellow
BLUE = \033[1;34m       # Blue
PURPLE = \033[1;35m     # Purple
CYAN = \033[1;36m        # Cyan
WHITE = \033[1;37m       # White

#! Commands
CC = cc
RM = rm -f
AR = ar -rc

#! Flags
CFLAGS = -Wall -Wextra -Werror
MKFLAGS = --no-print-directory

#! Folders
DEPS = includes
SRCS = .

#! Files
CLIENT = client
SERVER = server
PRINTF = ft_printf/libftprintf.a

SOURCE_S = server.c utils.c
SOURCE_C = client.c utils.c

OBJ_SERVER = $(SOURCE_S:%.c=%.o)
OBJ_CLIENT = $(SOURCE_C:%.c=%.o)
#! Rules

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	@echo "[${CYAN}Compiling${RESET}]"
	@make $(MKFLAGS) -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(CLIENT) -I $(DEPS)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(SERVER) -I $(DEPS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	@echo "[${CYAN}Cleaning${RESET}] "
	@make clean $(MKFLAGS) -C ft_printf
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) 

fclean: clean
	@make fclean $(MKFLAGS) -C ft_printf
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: re fclean all clean
