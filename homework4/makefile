CC := g++
OPTS := -std=c++11
FLAGS := -O0 -g3 -Wall -c -fmessage-length=0
app.exe: main.o bus.o
	$(CC) $(OPTS) $^ -o $@
%.o: %.cpp %.h
	$(CC) $(OPTS) $(FLAGS) -c $<
clean:
	rm *.o *.exe
