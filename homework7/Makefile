CC := g++
OPTS := -std=c++11 -Werror -Wall -pedantic
CFLAGS := -O0 -fprofile-arcs -ftest-coverage

app.exe: *.o 
	$(CC) $(OPTS) $(CFLAGS) $^ -o $@
%.o: %.cpp *.h
	$(CC) $(OPTS) $(CFLAGS) -c $<
clean:
	rm *.o *.exe *.gcda *.gcno *.gcov

valgrind:
	valgrind --tool=memcheck --leak-check=full ./app.exe
