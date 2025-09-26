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

CFLAGS = -Wall -Wextra -Werror

NASM = nasm 

NASM_FLAGS = -f elf64

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(OBJ_DIR)%.o:$(SRCS_DIR)%.s | $(OBJ_DIR)
	$(NASM) $(NASM_FLAGS) -o $@ $<

test: $(NAME) $(SRCS_TEST)
	gcc $(CFLAGS) -o $(NAME_TEST) $(SRCS_TEST) -L. -lasm
	./$(NAME_TEST)

re: fclean all

clean:
	rm -rf srcs/objs/

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

