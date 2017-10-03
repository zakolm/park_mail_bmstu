CC := gcc
OPTS = -g0
CFLAGS := -std=c11

main.exe : main.o matrix.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
	
clean :
	rm *.o *.exe
