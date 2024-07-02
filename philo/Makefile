# Created by: Youssef El Mountahi
# define colors
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m
NC=\033[0m

NAME = philo
CC = cc
setters_files = ft_last_meal.c
setters_pre = $(addprefix settersAndGetters/, $(setters_files))
simulation_files = ft_monitoring.c ft_print_philo_info.c ft_simulation.c ft_start_simulation.c ft_go_sleep.c ft_think.c ft_take_forks.c ft_put_forks.c\
ft_eat.c ft_check_philo_exit.c
simulation_pre = $(addprefix simulation/, $(simulation_files))
treads_files = ft_create_mutexes.c ft_init_info.c ft_init_philosophers.c
treads_pre = $(addprefix threads/, $(treads_files))
utils_files =  ft_atoi.c ft_isdigit.c ft_validate_args.c ft_print_error.c ft_print_success.c\
ft_play_with_time.c rasie_condition.c ft_get_time.c ft_log.c ft_sleep.c ft_print_died.c
utiles_pre = $(addprefix utils/, $(utils_files))
files = main.c $(utiles_pre) $(treads_pre) $(simulation_pre) $(setters_pre)
header = philosophers.h
SOBJ = $(files:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
#  -g -fsanitize=address
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
mc : $(NAME) clean
fclean: clean
	@echo "$(RED)Cleaning $(NAME) ...$(NC)"
	@$(RM) $(NAME)

re: fclean all philo