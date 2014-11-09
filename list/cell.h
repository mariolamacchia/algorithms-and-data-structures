#ifndef _CELL_H
#define _CELL_H

template <class T>
class Cell 
{
    public:
        Cell() {next = NULL; previous = NULL;}
        ~Cell() {}

        T getValue() {return value;}
        void setValue(T v) {value = v;}

        Cell* getNext() {return next;}
        void setNext(Cell* c) {next = c;}

        Cell* getPrevious() {return previous;}
        void setPrevious(Cell* c) {previous = c;}

    private:
        T value;
        Cell<T>* next;
        Cell<T>* previous;
        static const T EMPTY_VALUE;
};

#endif
