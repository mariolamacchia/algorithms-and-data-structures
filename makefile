CC = g++
CFLAGS = -Wall -g
FILES = tests.cpp

all: list1 list2 queue1 stack1 stack2 bintree1 bintree2 tree1 tree2

list2:
	cp list/list2.h list/list.h
	$(CC) $(CFLAGS) list/main.cpp $(FILES) -o list2.bin 
	rm list/list.h
list1:
	cp list/list1.h list/list.h
	$(CC) $(CFLAGS) -o list1.bin $(FILES) list/main.cpp
	rm list/list.h

queue1:
	$(CC) $(CFLAGS) -o queue.bin $(FILES) queue/main.cpp

stack1:
	cp stack/stack1.h stack/stack.h
	$(CC) $(CFLAGS) -o stack1.bin $(FILES) stack/main.cpp stack/algorithms.cpp
	rm stack/stack.h

stack2:
	cp stack/stack2.h stack/stack.h
	$(CC) $(CFLAGS) -o stack2.bin $(FILES) stack/main.cpp stack/algorithms.cpp
	rm stack/stack.h

bintree1:
	cp binary-tree/binary-tree1.h binary-tree/binary-tree.h
	$(CC) $(CFLAGS) -o bintree1.bin $(FILES) binary-tree/main.cpp
	rm binary-tree/binary-tree.h

bintree2:
	cp binary-tree/binary-tree2.h binary-tree/binary-tree.h
	$(CC) $(CFLAGS) -o bintree2.bin $(FILES) binary-tree/main.cpp
	rm binary-tree/binary-tree.h

tree2:
	cp tree/tree2.h tree/tree.h
	$(CC) $(CFLAGS) -o tree2.bin $(FILES) tree/main.cpp
	rm tree/tree.h

tree1:
	cp tree/tree1.h tree/tree.h
	$(CC) $(CFLAGS) -o tree1.bin $(FILES) tree/main.cpp
	rm tree/tree.h

set1:
	cp list/list1.h list/list.h
	$(CC) $(CFLAGS) -o set1.bin $(FILES) set/main.cpp
	rm list/list.h

set2:
	$(CC) $(CFLAGS) -o set2.bin $(FILES) set-array/main.cpp \
	    set-array/set.cpp set-array/operations.cpp

clean:
	rm *.bin
	rm -rf *.dSYM
