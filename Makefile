CC = cc
files = main.c
mandatory_prefix = "mandatory"
mandatory_files = $(addprefix $(mandatory_prefix), $(files))
header = $(addprefix $(mandatory_prefix), "philosophers.h")
CFLAGS = -Wall -Wextra -Werror
NAME = philo
RM = rm -f

all: $(NAME)
$(NAME): $(mandatory_files)
	$(CC) $(CFLAGS) -o $(NAME) $(mandatory_files)
clean:
	rm -f $(NAME)
