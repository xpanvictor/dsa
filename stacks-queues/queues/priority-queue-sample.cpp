// Sample program to use STL priority queues members

#include <iostream>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

class SmallerHuman
{
public:
    SmallerHuman(char *_name, int _age)
    {
        name = _name;
        age = _age;
    }
    bool operator<(const SmallerHuman &p) const
    { // oh const referencing-forgotten the actual name
        return strcmp(name, p.name);
    }
    bool operator>(const SmallerHuman &p) const
    {
        return (this->name != p.name) && !(*this < p);
    }
    friend ostream &operator<<(ostream &out, const SmallerHuman &p1)
    {
        out << p1.name << "---" << p1.age << endl;
        return out;
    }
    int get_age() { return age; }

private:
    char *name;
    int age;
};

class lesserAge
{
public:
    bool operator()(SmallerHuman &h1, SmallerHuman &h2) const
    {
        return h1.get_age() < h2.get_age();
    }
};

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

    // Let's test out the implementation with a function object for prioritizing
    SmallerHuman people[] = {SmallerHuman("victor", 9), SmallerHuman("xpan", 12)};

    priority_queue<SmallerHuman> hq1(people, people + 2);
    priority_queue<SmallerHuman, vector<SmallerHuman>, greater<SmallerHuman>> hq2(people, people + 2);
    priority_queue<SmallerHuman, vector<SmallerHuman>, lesserAge> hq3(people, people + 2);

    cout << "hq1 uses '<' for lexicographical ordering" << endl;
    while (!hq1.empty())
    {
        // popping requires removing the first element
        // however, STL queue return for pop is void, so we retrieve first
        SmallerHuman top_val = hq1.top(); // first store top value of queue
        hq1.pop();
        cout << top_val; // Overloaded << operator to print SmallerHuman object
    }

    cout << "hq2 uses '>' for lexicographical ordering" << endl;
    while (!hq2.empty())
    {
        // popping requires removing the first element
        // however, STL queue return for pop is void, so we retrieve first
        SmallerHuman top_val = hq2.top(); // first store top value of queue
        hq2.pop();
        cout << top_val; // Overloaded << operator to print SmallerHuman object
    }

    cout << "hq3 uses user defined lesser member function for age ordering" << endl;
    while (!hq3.empty())
    {
        // popping requires removing the first element
        // however, STL queue return for pop is void, so we retrieve first
        SmallerHuman top_val = hq3.top(); // first store top value of queue
        hq3.pop();
        cout << top_val; // Overloaded << operator to print SmallerHuman object
    }

    return 0;
}
