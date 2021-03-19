#ifndef ADTQueue_H
#define ADTQueue_H

class ADTQueue{
    public:
        virtual void push(int x) = 0;
        virtual void pop() = 0;
        virtual int front() = 0;
        virtual int size() = 0;
        virtual bool empty() = 0;
};
#endif