CC := g++
OPTS := -std=c++11 #-Werror -Wall

app.exe: main.o vector.o
	$(CC) $(OPTS) $^ -o $@
%.o: %.cpp *.h
	$(CC) $(OPTS) -c $<
clean:
	rm *.o *.exe
