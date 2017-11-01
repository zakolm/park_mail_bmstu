CC := g++
OPTS := -std=c++11
FLAGS := -Wall -O0 -g3 

app.exe: main.o figure.o auxiliary_file.o
	$(CC) $(OPTS) $^ -o $@
%.o: %.cpp %.h
	$(CC) $(OPTS) $(FLAGS) -c $<
clean:
	rm *.o *.exe
