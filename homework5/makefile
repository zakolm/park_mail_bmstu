CC := g++
OPTS := -std=c++11

app.exe: main.o MyString.o
	$(CC) $(OPTS) $^ -o $@
%.o: %.cpp %.h
	$(CC) $(OPTS) -c $<
clean:
	rm *o *.exe
