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

priority1:
	cp priority-queue/priority-queue1.h priority-queue/priority-queue.h
	$(CC) $(CFLAGS) -o priority1.bin $(FILES) priority-queue/main.cpp
	rm priority-queue/priority-queue.h

priority2:
	cp priority-queue/priority-queue2.h priority-queue/priority-queue.h
	cp binary-tree/binary-tree1.h binary-tree/binary-tree.h
	$(CC) $(CFLAGS) -o priority2.bin $(FILES) priority-queue/main.cpp
	rm priority-queue/priority-queue.h
	rm binary-tree/binary-tree.h

dict1:
	cp list/list1.h list/list.h
	cp dict/dict1.h dict/dict.h
	$(CC) $(CFLAGS) -o dict1.bin $(FILES) dict/main.cpp dict/hash.cpp
	rm list/list.h
	rm dict/dict.h

dict2:
	cp dict/dict2.h dict/dict.h
	$(CC) $(CFLAGS) -o dict2.bin $(FILES) dict/main.cpp dict/hash.cpp \
	    dict/selection.cpp
	rm dict/dict.h

dict3:
	cp dict/dict3.h dict/dict.h
	$(CC) $(CFLAGS) -o dict3.bin $(FILES) dict/main.cpp dict/hash.cpp \
	    dict/selection.cpp
	rm dict/dict.h

clean:
	rm *.bin
	rm -rf *.dSYM
