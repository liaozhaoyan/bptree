CC ?= gcc
CFLAGS ?= -O3 -g
ELF = test

all: $(ELF)

%.o: %.c bplustree.h
	$(CC) -c $(CFLAGS) $(LUA_CFLAGS) -o $@ $<

$(ELF): bplustree.o test.o
	$(CC) bplustree.o test.o -o $@

clean:
	rm -f $(ELF) *.o *.rock