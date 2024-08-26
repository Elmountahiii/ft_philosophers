# Created by: Youssef El Mountahi
# define colors
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m
NC=\033[0m

NAME = philo_bonus
CC = cc

utils_files = ft_atoi.c ft_isdigit.c
init_files = ft_init_philos.c
simlation_files = ft_simulation.c
simlation_pre = $(addprefix simulation/, $(simlation_files))
utils_pre= $(addprefix utils/, $(utils_files)) 
init_pre = $(addprefix init/, $(utils_files))
files = main_bonus.c $(utils_pre) $(utils_files) $(init_pre) $(simlation_pre)
header = philosophers_bonus.h
SOBJ = $(files:.c=.o)
CFLAGS = -Wall -Wextra -Werror 

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

.PHONY: all clean fclean re
