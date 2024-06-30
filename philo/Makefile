# Created by: Youssef El Mountahi
# define colors
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m
NC=\033[0m

NAME = philo
CC = cc
clean_files = ft_clean.c ft_clean_mutexes.c ft_free.c
clean_pre = $(addprefix clean/, $(clean_files))
simulation_files = ft_monitoring.c  ft_simulation.c ft_start_simulation.c ft_go_sleep.c ft_think.c ft_take_forks.c ft_put_forks.c\
ft_eat.c ft_check_philo_exit.c ft_check_death.c  ft_check_monitor_exit.c 
simulation_pre = $(addprefix simulation/, $(simulation_files))
treads_files = ft_create_mutexes.c ft_init_info.c ft_init_philosophers.c
treads_pre = $(addprefix threads/, $(treads_files))
utils_files =  ft_atoi.c ft_isdigit.c ft_validate_args.c ft_print_error.c \
ft_get_time.c ft_log.c ft_sleep.c ft_print_died.c
utiles_pre = $(addprefix utils/, $(utils_files))
files = main.c $(utiles_pre) $(treads_pre) $(simulation_pre) $(clean_pre)
header = philosophers.h
SOBJ = $(files:.c=.o)
CFLAGS = -Wall -Wextra -Werror -pthread 
#  -fsanitize=thread
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
	@rm -rf $(SOBJ)
mc : $(NAME) clean
fclean: clean
	@echo "$(RED)Cleaning $(NAME) ...$(NC)"
	@$(RM) $(NAME)

re: fclean all philo
.PHONY: all clean fclean re