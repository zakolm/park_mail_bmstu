CC := g++
OPTS := -std=c++11 #-Werror -Wall

app.exe: main.o 
	$(CC) $(OPTS) $^ -o $@
%.o: %.cpp *.h
	$(CC) $(OPTS) -c $<
clean:
	rm *.o *.exe
