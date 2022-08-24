TARGET ?= run
OBJS := main.o function.o
CC := cc
CFLAGS := -c -o

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
%.o:%.c
	$(CC) $< $(CFLAGS) $@
clean:
	rm -f $(OBJS) 
