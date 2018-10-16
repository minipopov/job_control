CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= job

HEADERS	= ./includes ./libft/includes

SOURCES	= ./srcs/continue_job.c		./srcs/do_job_notification.c	./srcs/exec_process.c			\
	./srcs/info_job.c		./srcs/init_job.c		./srcs/init_job_control.c		\
	./srcs/init_process.c		./srcs/is_shell_terminal.c	./srcs/job_control_add.c		\
	./srcs/job_control_add_job.c	./srcs/main.c			./srcs/mark_job_as_running.c		\
	./srcs/mark_process_status.c	./srcs/put_job_in_background.c	./srcs/put_job_in_foreground.c		\
	./srcs/run_job.c		

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

makelib	: 
	make -C libft/

cleanlib	: 
	make clean -C libft/

fcleanlib	: 
	make fclean -C libft/

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ) ./libft/libft.a

clean	: cleanlib
	rm -f $(OBJ)

re	: fcleanlib fclean all

fclean	: cleanlib clean
	rm -f $(NAME)

