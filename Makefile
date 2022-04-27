NAME=libasm.a
SRCS=ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_BONUS=ft_atoi_base_bonus.s
OBJS=$(SRCS:.s=.o)
OBJS_BONUS=$(SRCS_BONUS:.s=.o)
NASM_FLAG=-f macho64
TEST_NAME=test
TEST_BONUS_NAME=test_bonus

%.o:	%.s
	nasm $(NASM_FLAG) $<

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -rf $(NAME) $(TEST_NAME) $(TEST_BONUS_NAME)

re:	fclean	all

bonus:	$(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

test:	$(NAME)
	gcc -L. -lasm -o test main.c
	./test

test_bonus:	bonus
	gcc -L. -lasm -o test_bonus main_bonus.c
	./test_bonus

.PHONY:	clean fclean re bonus test test_bonus

