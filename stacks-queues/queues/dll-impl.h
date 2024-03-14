
#ifndef DLL_QUEUE_H
#define DLL_QUEUE_H

#include <list>

template <class T>
class Queue
{
public:
    Queue() {}

    void clear()
    {
        lst.clear();
    }
    bool isEmpty()
    {
        return lst.empty();
    }
    T &front()
    {
        return lst.front();
    }
    T dequeue()
    {
        // store first element temporarily
        T el = lst.front();
        el.pop_front();
        return el;
    }
    void enqueue(const T &el)
    {
        lst.push_back(el);
    }

private:
    list<T> lst;
};

#endif