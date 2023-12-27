#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <class T>
class DLLNode
{
public:
    DLLNode()
    {
        prev = next = 0;
    }

    DLLNode(const T &el, DLLNode *pv = 0, DLLNode *nx = 0)
    {
        info = el;
        prev = pv, next = nx;
    }

    DLLNode *prev, *next;
    T info;
};

template <class T>
class DoublyLinkedList
{
public:
    DOUBLY_LINKED_LIST()
    {
        head = tail = 0;
    }

    ~DOUBLY_LINKED_LIST();

    void addToDLLTail(const T &el);
    T deleteFromDLLTail();

private:
    DLLNode<T> *head, *tail;
};

#endif // DOUBLY_LINKED_LIST