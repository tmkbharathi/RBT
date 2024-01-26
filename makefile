EXECUTABLE = a.out
SOURCES = main.c insert.c rotate.c find_max.c find_min.c delete.c delete_max.c delete_min.c

OBJECTS = $(SOURCES:.c=.o)
CC = gcc

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: run clean

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)


