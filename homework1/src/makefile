CC := gcc
OPTS = -g0
CFLAGS := -std=c11

main.exe : main.o result.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) $(OPTS) -c $<
	
clean :
	rm *.o *.exe
	
check_memory: main.exe
	valgrind --tool=memcheck ./$^