#ifndef STACK_H
#define STACK_H

#include <vector>

using namespace std;

// // Operations of the stack
// - push
// - pop
// - clear
// - isEmpty
// - topEl

template <class T, int capacity = 30>
class VStack
{
public:
    VStack()
    {
        // reserve the space for the pool
        pool.reserve(capacity);
    }

    bool isEmpty()
    {
        return pool.empty();
    }

    void push(el : T)
    {
    }

private:
    vector<T> pool;
};

#endif