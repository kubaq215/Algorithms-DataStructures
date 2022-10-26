#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:

    class Node
    {
    public:
        int key{};
        Node *next{};

        Node(int k) : key{k} {}
    };

    Node *head;

public:

    Stack() = default;

    void push(int k);
    void pop();
    void peek();
    bool isEmpty();
    void size();
};

void Stack::push(int k)
{
    Node* node{new Node{k}};
    node->next = head;
    head = node;
    cout << "Dodano wartosc " << k << endl;
}

void Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stos jest pusty" << endl;
        return;
    }

    Node* temp{head};
    int key{head->key};
    head = head->next;
    delete temp;
    
    cout << "Zdjeto element ktory mial wartosc " << key << endl;
}

void Stack::peek()
{
    if(not isEmpty())
    {
        cout << "Wartosc na wierzchu wynosi " << head->key << endl;
    }
    else
    {
        cout << "Nie ma na co patrzec" << endl;
    }
}

bool Stack::isEmpty()
{
    return head == nullptr;
}

void Stack::size()
{
    if(not isEmpty())
    {
        int k = 1;
        Node* node1{head};
        while(node1->next != NULL)
        {
            node1 = node1->next;
            k++;
        }
        cout << "Stos ma wielkosc " << k << endl;
        return;
    }
}

int main()
{
    Stack st{};
    cout << st.isEmpty() << endl;
    st.pop();
    st.peek();
    st.push(3);
    st.push(8);
    st.push(12);
    cout << st.isEmpty() << endl;
    st.peek();
    st.pop();
    st.push(13);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.push(2);
    st.size();
}