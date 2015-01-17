#ifndef _SET_H
#define _SET_H

class Set
{
    public:
        typedef int cell;

        Set();

        bool isEmpty() const;
        int getFirst() const;
        int getNext(int) const;
        int read(int) const;

        bool isEndOfSet(int) const;
        bool has(int) const;

        void insert(int);
        void remove(int);
    private:
        static const int maxLength = 1000;
        bool values[maxLength];
};

#endif
