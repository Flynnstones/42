Library = libset

files = ft_memset \
        ft_bzero

Compiler = gcc
CmpFlags = -Wall -Wextra -Werror

OUTN = $(Library).a
CFILES = $(files:%=%.c)
OFILES = $(files:%=%.o)
NAME = $(OUTN)
MAIN = main

$(NAME): $(OFILES)
	$(Compiler) $(CmpFlags) -c $(CFILES) -I./
	ar -rcs $(OUTN) $(OFILES)

lib: $(NAME)

$(MAIN): $(NAME)
	$(Compiler) $(CmpFlags) -o $(MAIN) $(MAIN).c -L. -lset

all: lib $(MAIN)

clean:
	rm -f $(MAIN) $(OFILES)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean re lib