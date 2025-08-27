SRCS_DIR = srcs/asm/
SRCS = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s

SRCS_TEST = srcs/tester/tester.c
NAME_TEST = testeur
OBJ_DIR = srcs/objs/

OBJ = $(SRCS:%.s=$(OBJ_DIR)%.o)

NAME = libasm.a

CFLAGS = -Wall -Wextra -Werror -g3

NASM = nasm 

NASM_FLAGS = -f elf64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(OBJ_DIR)%.o:$(SRCS_DIR)%.s
	mkdir -p srcs/objs
	$(NASM) $(NASM_FLAGS) -o $@ $<

test: $(NAME) $(SRCS_TEST)
	gcc $(CFLAGS) -o $(NAME_TEST) $(SRCS_TEST) -L. -lasm
	./$(NAME_TEST)

clean:
	rm -rf srcs/objs/

fclean: clean
	rm $(NAME)
	rm $(NAME_TEST)

