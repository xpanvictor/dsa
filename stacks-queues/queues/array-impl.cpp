
#include "array-impl.h"

// this is placing el at the end of the queue
template <class T, int size>
void ArrayQueue<T, size>::enqueue(const T &el)
{
    // ensure array isnt full
    if (!isFull())
    {
        // case we have last element at end already, also first element case
        if (last == size - 1 || last == -1)
        {
            // place new item in beginning since there's space there
            storage[0] = el;
            last = 0;
            // check if queue was empty before, hence update first
            if (first == -1)
                first = 0;
        }
        else
            storage[++last] = el; // normal case
    }
    else
    {
        std::cout << "Queue full" << endl;
    }
}

// this is removing the first element in the queue
template <class T, int size>
T ArrayQueue<T, size>::dequeue()
{
    // check if array aint empty
    if (!isEmpty())
    {
        // temporay for the first element
        T tmp = storage[first];
        // now remove first element psuedo pointer
        if (first == last) // case of one element
            first = last = -1;
        else if (first == size - 1) // case where first is already on last index
            first = 0;
        // normal case, just increase first to be on next element
        else
            first++;
    }

    else
        cout << "Queue is empty"
}
