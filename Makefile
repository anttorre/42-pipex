#jot -r 11 1 50 | tr '\n' ' ' | awk '!a[$0]++'   -> Crea 11 numeros random entre 1 y 50 sin repetir
#./push_swap 58 65 25 11 8 9 2 1 66 42 14 59
#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PUSH_SWAP = pipex.a

#PUSH_SWAP_BONUS = pipex_bonus.a

LIB = ar rcs

SRCS = src/pipex.c src/initialize_struct.c src/arguments.c src/pipex_utils.c src/split_quotes_utils.c

OBJS = $(SRCS:.c=.o)

#SRCS_BONUS = srcb/checker.c

#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) :	$(OBJS) $(LIBFT)
			@echo "$(MAGENTA)$(BOLD)Compiling pipex...$(RESET)"
			@$(LIB) $(PUSH_SWAP) $(OBJS)
			@$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)
			@echo "$(CYAN)$(BOLD)Done$(RESET)"

$(OBJS):	src/%.o : src/%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

#$(NAME_BONUS): $(OBJS_BONUS) $(OBJS) $(LIBFT)
#			@echo "$(YELLOW)$(BOLD)Compiling push_swap bonus...$(RESET)"
#			@$(LIB) $(PUSH_SWAP_BONUS) $(OBJS_BONUS) $(OBJS)
#			@rm -rf src/push_swap.o
#			@$(CC) $(CFLAGS) $(PUSH_SWAP_BONUS) $(LIBFT) -o $(NAME_BONUS)
#			@echo "$(CYAN)$(BOLD)Done$(RESET)"

#$(OBJS_BONUS):	srcb/%.o : srcb/%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@make -s -C $(LIBFT_PATH)
			@make bonus -s -C $(LIBFT_PATH)

all : $(NAME)

bonus : $(NAME_BONUS)

clean:
			@echo "$(RED)$(BOLD)Cleaning objects from pipex...$(RESET)"
			@rm -f $(OBJS) $(OBJS_BONUS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make clean -s -C $(LIBFT_PATH)

fclean:
			@echo "$(RED)$(BOLD)Cleaning all files from pipex...$(RESET)"
			@rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(PUSH_SWAP) $(PUSH_SWAP_BONUS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make fclean -s -C $(LIBFT_PATH)

re : fclean all

pipe : all clean

.PHONY : all re fclean clean bonus pipe	