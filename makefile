CC = g++
CFLAGS = -Wall

all: list1 list2 queue1 stack1 stack2

list2:
	cp list/list2.h list/list.h
	$(CC) $(CFLAGS) list/main.cpp -o list2.bin 
	rm list/list.h
list1:
	cp list/list1.h list/list.h
	$(CC) $(CFLAGS) -o list1.bin list/main.cpp
	rm list/list.h

queue1:
	$(CC) $(CFLAGS) -o queue.bin queue/main.cpp

stack1:
	cp stack/stack1.h stack/stack.h
	$(CC) $(CFLAGS) -o stack1.bin stack/main.cpp stack/algorithms.cpp
	rm stack/stack.h

stack2:
	cp stack/stack2.h stack/stack.h
	$(CC) $(CFLAGS) -o stack2.bin stack/main.cpp stack/algorithms.cpp
	rm stack/stack.h

clean:
	rm *.bin
