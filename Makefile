NAME= petri_network

##########################  OS check

OS = $(shell uname)
ifeq ($(OS), Darwin)
CC=cc
GFLAGS= -Werror -Wall -Wextra -fsanitize=address 
else ifeq ($(OS), Linux)
CC=gcc
GFLAGS= -Werror -Wall -Wextra
endif

mode=0
PROD=0
TEST=1
NOFLAGS=2

SRCS_MAIN= main.c
SRCS_PETRI= $(wildcard network/*.c)
SRCS_UTILS= $(wildcard network/utils/**/*.c)
SRCS_TEST= $(wildcard unit_test/*.c)

ifeq ($(mode), $(PROD))
%.o:%.c
	$(CC) $(GFLAGS) -c $< -o $@
else ifeq ($(mode), $(NOFLAGS))
%.o:%.c
	$(CC) -c $< -o $@
endif

OBJS_MAIN=$(SRCS_MAIN:%.c=%.o)
OBJS_PETRI=$(SRCS_PETRI:%.c=%.o)
OBJS_UTILS=$(SRCS_UTILS:%.c=%.o)

# Test env:

OBJS_TEST=$(SRCS_TEST:%.c=%.o)

DATE=$(shell date -Iseconds)
BRANCH=$(shell git branch --show-current)
gcom=
EMPTY=

ifeq ($(mode), $(TEST))
OBJS= $(OBJS_TEST)
else
OBJS= $(OBJS_MAIN) $(OBJS_PETRI)  $(OBJS_UTILS) 
endif

.PHONY: clean fclean run git testenv

$(NAME): $(OBJS)
ifeq ($(mode), $(PROD))
	$(CC) $(GFLAGS) $(OBJS)  -o $(NAME)
else ifeq ($(mode), $(NOFLAGS))
recall:  $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
endif

run: $(NAME)
ifeq ($(OS), Darwin)
	./$(NAME)
else ifeq ($(OS), Linux)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME)
endif

# cleaning rules

clean:
	rm -f $(OBJS) $(OBJS_TEST)

fclean: clean
	rm -f $(NAME) test_unit 

t: $(OBJS) $(OBJS_TEST)
ifeq ($(OS), Darwin)
	$(CC) $(GFLAGS) -fsanitize=address  $(OBJS) $(OBJS_TEST) -o test_unit 
	./test_unit
else ifeq ($(OS), Linux)
	$(CC) $(OBJS) $(OBJS_TEST)  -o $(NAME)
	valgrind --leak-check=full --log-file=filename  -s ./test_unit
endif


all: $(NAME)

re: clean fclean all
