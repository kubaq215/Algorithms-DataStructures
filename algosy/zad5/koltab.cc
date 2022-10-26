#include <bits/stdc++.h>

using namespace std;

class Queue
{
    private:

        int n;
        int first = 0;
        int noe = 0;
        int *tab;
    
    public:

        Queue(int x);
        ~Queue();
        bool empty();
        int front();
        void push(int k);
        void pop(); 
        void print();
};

Queue::Queue(int x)
{
    n = x;
    tab = new int [x];
}

Queue::~Queue()
{
    delete[] tab;
}

bool Queue::empty()
{
    return noe == 0;
}

const int pusta = -2000000;

int Queue::front()
{
    if(not empty())
        return tab[first];
    return pusta;
}

void Queue::push(int k)
{
    if(noe < n)
    {
        int i = first + noe++;
        if(i >= n) i -= n;
        tab[i] = k;
    }
}

void Queue::pop()
{
    if(noe)
    {
        noe--;
        first++;
        if(first == n) first = 0;
    }
}

void Queue::print()
{
    for(int i=0; i<noe; i++)
        cout << tab[(first + i) % n] << "<-";
        cout << endl;
}

int main()
{
    Queue q = Queue(10);
    cout << "pusta? " << q.empty() << endl;
    q.push(2);
    q.push(5);
    q.push(7);
    q.push(1);
    q.print();
    cout << "poczatek - " << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << "pusta? " << q.empty() << endl;
    cout << "poczatek - " << q.front() << endl;
    q.print();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.print();
}