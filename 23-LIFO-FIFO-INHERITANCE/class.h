#ifndef CLASS_H
#define CLASS_H

struct transition;

class storage {
    protected:
        transition *T;
        transition *tmp;
    public:
        storage();
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
