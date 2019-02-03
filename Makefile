SRC = main.c prompter.c list_utils.c global_var.c defragment.c
INCL = $(SRC:.c=.h)
OBJ = $(SRC:.c=.o)
EXE = linked_list

CC = gcc
CFLAGS = -Wall -Werror
RM = rm

$(EXE): $(OBJ)
	cat MAKE_PROMPT && \
	$(CC) -o $(EXE) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $*.c

clean: 
	rm -f $(OBJ) $(EXE)