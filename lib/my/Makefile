##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Lib 2.0
##

LIB_PATH	=	../../include
SRC_PATH	=	./src

SRC	=	$(SRC_PATH)/my_putstr.c\
		$(SRC_PATH)/my_puterr.c\
		$(SRC_PATH)/my_getnbr_long.c\
		$(SRC_PATH)/my_strlen.c\
		$(SRC_PATH)/my_fusion_str.c\
		$(SRC_PATH)/my_compare_str.c\
		$(SRC_PATH)/my_get_word.c\
		$(SRC_PATH)/my_clear_malloc.c\
		$(SRC_PATH)/my_count_words.c\
		$(SRC_PATH)/my_putnbr.c\
		$(SRC_PATH)/my_itoa.c\
		$(SRC_PATH)/my_putfloat.c\
		$(SRC_PATH)/my_printf.c\
		$(SRC_PATH)/my_malloc.c\
		$(SRC_PATH)/my_create_chained.c \
		$(SRC_PATH)/my_destroy_chained.c\
		$(SRC_PATH)/my_create_array.c\
		$(SRC_PATH)/nmatch.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libepi.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	test -d $(LIB_PATH) || mkdir $(LIB_PATH)
	cp internal.h $(LIB_PATH)/
	mv $(LIB_PATH)/internal.h $(LIB_PATH)/epilib.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	test -d $(LIB_PATH) && rm -f $(LIB_PATH)/epilib.h

re:	fclean all
