CC = clang
override TARGET = chvm

override CFLAGS = -O3 -std=c99 -Iinclude/ -g

SOURCES := $(wildcard src/*.c)
OBJECTS := $(SOURCES:.c=.o)

.PHONY: $(TARGET) clean run
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)