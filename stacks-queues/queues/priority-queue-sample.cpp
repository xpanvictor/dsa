// Sample program to use STL priority queues members

#include <iostream>
#include <queue>

using namespace std;

int main()
{

    // P_Queue with less for ordering the elements & vector imp
    priority_queue<int> p1; // Less has the bigger number with higher priority
    // P_Queue with greater for ordering and vector impl
    priority_queue<int, vector<int>, greater<int>> p2; // > Lower number Higher Priority
    // array with some data
    int nums[] = {4, 6, 5};

    // P_queue using nums as iterator to supply value
    priority_queue<int> p3(nums, nums + 3);

    // Now fill in p1 with 3, 1, 2
    p1.push(3);
    p1.push(1);
    p1.push(2);
    // Fill in p2 with same data
    p2.push(3);
    p2.push(1);
    p2.push(2);

    // Now let's dequeue to see the way they are ordered
    cout << "P1 uses '<' where bigger number has higher priority" << endl;
    while (!p1.empty())
    {
        // popping requires removing the first element
        // however, STL queue return for pop is void, so we retrieve first
        int top_val = p1.top(); // first store top value of queue
        p1.pop();
        cout << top_val << endl;
    }

    cout << "P2 uses '>' where smaller number has bigger priority" << endl;
    while (!p2.empty())
    {
        // popping requires removing the first element
        // however, STL queue return for pop is void, so we retrieve first
        int top_val = p2.top(); // first store top value of queue
        p2.pop();
        cout << top_val << endl;
    }

    cout << "P3 uses '<' as well but with an iterator for queue initialization" << endl;
    while (!p3.empty())
    {
        // popping requires removing the first element
        // however, STL queue return for pop is void, so we retrieve first
        int top_val = p3.top(); // first store top value of queue
        p3.pop();
        cout << top_val << endl;
    }

    return 0;
}
