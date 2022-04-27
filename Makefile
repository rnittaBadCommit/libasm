NAME=libasm
SRCS=ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_strdup.s ft_atoi_base.s test.s
OBJS=$(SRCS:.s=.o)
NASM_FLAG=-f macho64

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:	%.s
	nasm $(NASM_FLAG) $<

test:	$(OBJS) main.c
	gcc main.c $(OBJS)
	$(NAME) 2>/dev/null

bonus:	$(OBJS) main_bonus.c
	gcc main_bonus.c $(OBJS)
	$(NAME) 2>/dev/null


clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
