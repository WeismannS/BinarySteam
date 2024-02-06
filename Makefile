SOURCES= server.c client.c
OBJECTS= $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTPRINTF_PATH = ft_printf
LIBFTPRINTF_LIB = $(LIBFTPRINTF_PATH)/libftprintf.a

all: server client

bonus: server client

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

server: server.o $(LIBFTPRINTF_LIB)
	$(CC) -o $@ $^

client: client.o $(LIBFTPRINTF_LIB)
	$(CC) -o $@ $^

$(LIBFTPRINTF_LIB):
	make -C $(LIBFTPRINTF_PATH)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFTPRINTF_PATH) clean

fclean: clean
	rm -f server client $(LIBFTPRINTF_LIB)

re: fclean all

.PHONY: all bonus clean fclean re
