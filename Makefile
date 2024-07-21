CC = gcc
CFLAGS = -Wall -g
TARGET = music_records
SRCS = main.c
OBJS = $(SRCS:.c=.o)
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(TARGET) $(OBJS)
.PHONY: all clean
