#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    class Node
    {
    public:
        int key{};
        Node* next{};
        
        Node(int k) : key{k}, next{nullptr} {}
    };
    
    Node *first, *last;
    
public:
    Queue() : first{nullptr}, last{nullptr} {}
    
    bool empty()
    {
        return first == nullptr;
    }
    int front();
    void push(int k);
    int pop();
    void print();
};

const int pusta = -2000000;

int Queue::front()
{
    if(not empty()) return first->key;
    return pusta;
}

void Queue::push(int k)
{
    if(empty())
    {
        first = new Node{k};
        last = first;
    }
    else
    {
        Node *p = new Node{k};
        last->next = p;
        last = last->next;
    }
}

int Queue::pop()
{
    int x;
    Node *p;
    
    if(not empty())
    {
        x = first->key;
        p = first;
        first = first->next;
        
        delete p;
    }
    
    return x;
}

void Queue::print()
{
    if(empty())
        cout << "Kolejka jest pusta!" << endl;
    
    for(Node *p=first; p!=nullptr; p = p->next)
        cout << p->key << " <- ";
        cout << endl;
    
}

int main()
{
    Queue q{};
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
