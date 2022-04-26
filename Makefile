NAME=./a.out
SRCS=ft_strlen.s ft_strcpy.s
OBJS=$(SRCS:.s=.o)
NASM_FLAG=-f macho64

all:	$(NAME)

$(NAME):	$(OBJS)

%.o:	%.s
	nasm $(NASM_FLAG) $<

test:	$(OBJS) main.c
	gcc main.c $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
