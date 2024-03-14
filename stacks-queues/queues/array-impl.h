
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <iostream>

template <class T, int size = 100>
class ArrayQueue
{
public:
    ArrayQueue()
    {
        // initialize first n last to -1 to mark empty list
        first = last = -1;
    }

    void enqueue(const T &el);
    T dequeue();
    bool isEmpty()
    {
        // the queue is empty when first is -1 especially last as well
        return first == -1;
    }
    bool isFull()
    {
        // queue is full if first element is at beginning and last at last
        // or beginning is right after the last
        return first == 0 && last == size - 1 || first == last + 1;
    }

private:
    int first, last;
    T storage[size];
};

#endif