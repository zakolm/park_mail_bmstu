CC := g++
OPTS := -std=c++11
FLAGS := -Wall -O0 -g3 -fmessage-lenght=0

app.exe: main.o
	$(CC) $(OPTS) $^ -o $@
%.o: %.cpp %.h
	$(CC) $(OPTS) $(FLAGS) -c $<
clean:
	rm *.o *.exe
