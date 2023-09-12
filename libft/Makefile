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

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = ar rcs

FILES =	ft_isalpha.c ft_isdigit.c\
		ft_isalnum.c ft_isascii.c\
		ft_isprint.c ft_strlen.c\
		ft_memset.c ft_bzero.c\
		ft_memcpy.c	ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c\
		ft_strchr.c	ft_strrchr.c\
		ft_strncmp.c ft_memchr.c\
		ft_memcmp.c	ft_strnstr.c\
		ft_atoi.c ft_calloc.c\
		ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c\
		ft_itoa.c ft_strmapi.c\
		ft_striteri.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c ft_split.c\
		ft_printf.c ft_print_char_string.c\
		ft_print_d_i_u.c ft_print_hex_ptr.c\
		struct.c write_flags.c\
		get_next_line_bonus.c get_next_line_utils_bonus.c\


BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c
		
OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJS)
			@echo "$(MAGENTA)$(BOLD)Compiling libft...$(RESET)"
			@$(LIB) $(NAME) $(OBJS)
			@echo "$(CYAN)$(BOLD)Done.$(RESET)"

$(OBJS) :	$(FILES)
			@$(CC) $(FLAGS) -c $(FILES)

$(OBJS_BONUS) :	$(BONUS)
			@$(CC) $(FLAGS) -c $(BONUS)

bonus : $(OBJS) $(OBJS_BONUS)
		@echo "$(YELLOW)$(BOLD)Compiling libft bonus...$(RESET)"
		@$(LIB) $(NAME) $(OBJS) $(OBJS_BONUS)
		@echo "$(CYAN)$(BOLD)Done.$(RESET)"

clean:
	@echo "$(RED)$(BOLD)Cleaning objects from libft...$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

fclean:
	@echo "$(RED)$(BOLD)Cleaning all files from libft...$(RESET)"
	@rm -f $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

re : fclean all

.PHONY : all re fclean clean bonus