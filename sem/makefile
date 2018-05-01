CFLAGS=-g
src=$(wildcard *.c)
TARGET=$(patsubst %.c,%,$(src))

.PHONY:all clean

all:$(TARGET)

%:%.c
	$(CC) $(CFLAGS) -o $@ $^
clean:
	$(RM) $(TARGET)
