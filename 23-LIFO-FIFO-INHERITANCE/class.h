#ifndef CLASS_H
#define CLASS_H
#define NULL __null

struct transition {
    int value;
    transition *next;
    transition(int _value): value(_value) {}
};

class storage {
    protected:
        transition *T;
        transition *tmp;
    public:
        storage(): T(NULL), tmp(NULL) {}
        ~storage();

        int pop();
        void print();
};

class LIFO : public storage {
    public:
        LIFO() : storage() {}
        ~LIFO();
        void push(int);
};

class FIFO : public storage {
    public:
        FIFO() : storage() {}
        ~FIFO();
        void push(int);
};
#endif 
