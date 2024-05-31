# Created by: Youssef El Mountahi
# define colors
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m
NC=\033[0m

NAME = philo
CC = cc
treads_files = ft_create_philosophers.c ft_clean.c
treads_pre = $(addprefix threads/, $(treads_files))
utils_files =  ft_atoi.c ft_isdigit.c ft_validate_args.c ft_init_philo.c ft_print_error.c ft_print_success.c\
ft_play_with_time.c
utiles_pre = $(addprefix utils/, $(utils_files))
files = main.c $(utiles_pre) $(treads_pre)
header = philosophers.h
SOBJ = $(files:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
# -g -fsanitize=address
RM = rm -f

all: $(NAME)

%.o: %.c $(header)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SOBJ) 
	@echo "$(BLUE)Compiling $(NAME) ... $(NC)"
	@$(CC) $(CFLAGS) $(SOBJ) -o $(NAME)
	@echo "$(GREEN)Done!$(NC)"
clean:
	@echo "$(RED)Cleaning Object Files ...$(NC)"
	@rm -f $(SOBJ)

fclean: clean
	@echo "$(RED)Cleaning $(NAME) ...$(NC)"
	@$(RM) $(NAME)

re: fclean all philo