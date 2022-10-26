#ifndef SET_HPP
#define SET_HPP

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Set
{
private:

    class Node
    {
    public:
        T key{};
        Node *next{};

        Node(T k) : key{k}, next{nullptr} {}
    };

    Node *head;

public:

    Set() : head{nullptr} {}

    bool isEmpty()
    {
        return head == nullptr;
    }

    void print();
    void insert(T value);
    void remove(T value);
    bool contains(T value);
    void Union(const Set &other);
    void intersection(const Set &other);
    void difference(const Set &other);
};

template <typename T>
void Set<T>::print()
{
    if(isEmpty())
    {
        cout << "empty" << endl;
        return;
    }
    Node *p;
    cout << "{";
    for(p=head; p->next!=nullptr; p = p->next)
    {
        cout << p->key << ", ";
    }
    cout << p->key;
    cout << "}" << endl;
}

template <typename T>
void Set<T>::insert(T value)
{
    if(isEmpty())
    {
        head = new Node{value};
    }
    else if(value < head->key)
    {
        Node *temp = new Node{value};
        temp->next = head;
        head = temp;
    }
    else if(!head->next)
    {
        head->next = new Node{value};
    }
    else
    {
        Node *temp = head->next;
        Node *prev = head;
        while(temp)
        {
            if(temp->key < value)
            {
                prev = temp;
                temp = temp->next;
            }
            else if(temp->key == value) return;
            else break;
        }
        Node *p = new Node{value};
        prev->next = p;
        p->next = temp;
    }
}

template <typename T>
void Set<T>::remove(T value)
{  
    if(head->key == value)
    {
        head = head->next;
    }
    else
    {
        Node *temp = head, *temp2;
        while(temp)
        {
            temp2 = temp->next;
            if(temp2->key == value) 
            {
                temp->next = temp2->next;
                delete temp2;
                break;
            }
            temp = temp->next;
        }
    }
}

template <typename T>
bool Set<T>::contains(T value)
{
    Node *temp = head->next;
    while(temp)
    {
        if(temp->key == value) 
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// template <typename T>
// void Set<T>::Union(const Set &other)
// {
//     Set<T> v;
//     Node *temp1 = head;
//     Node *temp2 = other.head;
//     while(temp1)
//     {
//         v.insert(temp1->key);
//         temp1 = temp1->next;
//     }
//     while(temp2)
//     {
//         v.insert(temp2->key);
//         temp2 = temp2->next;
//     }
//     cout << "Union product of 2 sets is ";
//     v.print();
// }

template <typename T>
void Set<T>::Union(const Set &other)
{
    Node *temp1 = head;
    Node *prev = new Node{-200000};
    prev->next = head;
    Node *temp2 = other.head;
    if(temp1->key > temp2->key)
    {
        Node *p = new Node{temp2->key};
        p->next = head;
        head = p;
        temp2 = temp2->next;
        prev = head;
    }
    while(temp1 || temp2)
    {
        if(temp1 && !temp2)
        {
            break;
        }
        else if(!temp1 && temp2)
        {
            prev->next = new Node{temp2->key};
            prev = prev->next;
            temp2 = temp2->next;
            continue;
        }
        if(temp1->key > temp2->key)
        {
            Node *p = new Node{temp2->key};
            prev->next = p;
            p->next = temp1;
            prev = prev->next;
            temp2 = temp2->next;
        }
        else if(temp1->key < temp2->key)
        {
            prev = prev->next;
            temp1 = temp1->next;
        }
        else if(temp1->key == temp2->key)
        {
            prev = prev->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    cout << "Union product of 2 sets is ";
    print();
}

template <typename T>
void Set<T>::intersection(const Set &other)
{
    Set<T> v;
    Node *temp1 = head;
    Node *temp2 = other.head;
    while(temp1 && temp2)
    {
        if(temp1->key < temp2->key)
        {
            temp1 = temp1->next;
        }
        else if(temp1->key > temp2->key)
        {
            temp2 = temp2->next;
        }
        else if(temp1->key == temp2->key)
        {
            v.insert(temp1->key);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    cout << "Intersection product of 2 sets is ";
    v.print();
}

template <typename T>
void Set<T>::difference(const Set &other)
{
    Set<T> v;
    Node *temp1 = head;
    Node *temp2 = other.head;
    while(temp1 || temp2)
    {
        if(temp1 && !temp2)
        {
            v.insert(temp1->key);
            temp1 = temp1->next;
            continue;
        }
        else if(!temp1 && temp2)
        {
            break;
        }
        if(temp1->key < temp2->key)
        {
            v.insert(temp1->key);
            temp1 = temp1->next;
        }
        else if(temp1->key > temp2->key)
        {
            temp2 = temp2->next;
        }
        else if(temp1->key == temp2->key)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    cout << "Difference product of 2 sets is ";
    v.print();
}

#endif