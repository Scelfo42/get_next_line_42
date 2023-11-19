NAME	:=	get_next_line

TESTFILE	:=	test

CC	:=	clang

DEBUG	:=	-g

INCLUDE	:=	-I include/

FLAGS	:=	-Wall -Wextra -Werror $(DEBUG)

SRCS	:=	srcs/get_next_line.c	\
			srcs/get_next_line_utils.c

BSRCS	:=	srcs/get_next_line_bonus.c	\
			srcs/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

# COLORS ================================================================= #

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
WHITE = \033[0;97m

# ======================================================================== #

%.o : %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiling:$(WHITE) $<"

all: create_test $(NAME)

create_test:
	if [ ! -f $(TESTFILE) ]; then \
		echo "This\nis\na\ntest" > $(TESTFILE); \
        echo "$(GREEN)Creating test file: $(WHITE)${TESTFILE}"; \
    fi

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${FLAGS}"
	@echo "$(YELLOW)- Includes: $(WHITE)${INCLUDE}"

create_test_bonus:
	if [ ! -f $(TESTFILE) ]; then \
		echo "This\nis\na\ntest" > $(TESTFILE); \
		echo "$(GREEN)Creating test file: $(WHITE)${TESTFILE}"; \
	fi
	if [ ! -f $(TESTFILE)2 ]; then \
		echo "This2\nis2\na2\ntest2" > $(TESTFILE)2; \
		echo "$(GREEN)Creating test file 2: $(WHITE)${TESTFILE}2"; \
	fi
	if [ ! -f $(TESTFILE)3 ]; then \
		echo "This3\nis3\na3\ntest3" > $(TESTFILE)3; \
		echo "$(GREEN)Creating test file 3: $(WHITE)${TESTFILE}3"; \
	fi

bonus: create_test_bonus $(BOBJS)
	$(CC) $(FLAGS) $(BOBJS) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${FLAGS}"
	@echo "$(YELLOW)- Includes: $(WHITE)${INCLUDE}"

clean:
	@rm -f $(OBJS)
	@rm -f $(BOBJS)
	@echo "$(RED)All $(CYAN)$(NAME)$(RED)'s objects removed with $(WHITE)${RM} $(YELLOW)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TESTFILE)
	@rm -f $(TESTFILE)2
	@rm -f $(TESTFILE)3
	@echo "$(RED)...$(CYAN)${NAME} and ${TESTFILE} $(RED)have been removed"

re: fclean all

.PHONY: all clean fclean re bonus
.SILENT:
