#include <bits/stdc++.h>

using namespace std;

const int HASH_SIZE = 10;

class HashTable 
{
private:
    struct Node {
        int key;
        int element;
        Node *next;
        Node(int n, int x) : key(n), next(NULL), element(x) {} 
    };

    Node **head;

public:
    HashTable(int size = HASH_SIZE);

    int rozmiar;
    bool insert(const int &x);
    bool remove(const int &x);
    bool contains(const int &x);
    int hash(const int &x);
    void makeEmpty();
    void print();
};

HashTable::HashTable(int size) : rozmiar{size}
{
    head = new Node *[size];
    for (int i=0; i<size; i++)
    {
        head[i] = NULL;
    }
}

int HashTable::hash(const int &x)
{
    return x % rozmiar;
}

bool HashTable::contains(const int &x)
{
    Node *temp;
    for (int i=0; i<rozmiar; i++)
    {
        temp = head[i];
        while(temp != NULL)
        {
            if(temp->element == x)
            {
                return 1;
            }
            Node *next = temp->next;
            temp = next;
        }
    }
    return 0;
}

bool HashTable::insert(const int &x)
{
    if(this->contains(x))
    {
        return 0;
    }

    int hx = hash(x);
    Node *temp = head[hx];

    if (temp != NULL)
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new Node(hx, x);
    }
    else
    {
        head[hx] = new Node(hx, x);
    }
    return 1;
}

void HashTable::print()
{
    cout << "----------------------------------" << endl;
    cout << "tablica:" << endl;

    for (int i=0; i<rozmiar; i++)
    {
        cout << i;

        Node *temp = head[i];

        while(temp != NULL)
        {
            cout << " -> " << temp->element ;
            temp = temp->next;
        }

        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

bool HashTable::remove(const int &x)
{
    int hx = hash(x);

    Node *pre = NULL;
    Node *temp = head[hx];
    
    while(temp != NULL && temp->element != x) 
    {
        pre = temp;
        temp = temp->next;
    }

    if(temp == NULL) { return 0; }

    if(pre == NULL) { head[hx]=temp->next; }
    else { pre->next=temp->next; }

    return 1;
}


void HashTable::makeEmpty()
{
    for (int i = 0; i < rozmiar; i++)
    {
        Node *temp = head[i];
        while (temp != NULL)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head[i] = NULL;
    }
}

int main()
{
    HashTable tab(10);

    tab.print();

    cout << "Insert(3): " << tab.insert(3) << endl;
    cout << "Insert(22): " << tab.insert(22) << endl;
    cout << "Insert(7): " << tab.insert(7) << endl;
    cout << "Insert(43): " << tab.insert(43) << endl;
    cout << "Insert(32): " << tab.insert(32) << endl;
    cout << "Insert(321): " << tab.insert(321) << endl;
    cout << "Insert(321): " << tab.insert(321) << endl;
    cout << "Insert(37): " << tab.insert(37) << endl;
    cout << "Insert(46): " << tab.insert(46) << endl;
    cout << "Insert(27): " << tab.insert(27) << endl;
    cout << "Insert(23): " << tab.insert(23) << endl;
    cout << "Insert(234): " << tab.insert(234) << endl;
    cout << "Insert(564): " << tab.insert(564) << endl;
    cout << "Insert(12): " << tab.insert(12) << endl;
    cout << "Insert(31): " << tab.insert(31) << endl;
    tab.print();

    cout<< "Remove(3): " << tab.remove(3) << endl;
    cout<< "Remove(43): " << tab.remove(43) << endl;
    cout<< "Remove(12): " << tab.remove(12) << endl;
    cout<< "Remove(321): " << tab.remove(321) << endl;
    cout<< "Remove(27): " << tab.remove(27) << endl;

    tab.print();

    cout << "Contains(31): " << tab.contains(31) << endl;
    cout << "Contains(77): " << tab.contains(77) << endl;

    cout << "makeEmpty " << endl;
    tab.makeEmpty();

    tab.print();

    cout << "Insert(46): " << tab.insert(46)<<endl;
    cout << "Insert(27): " << tab.insert(27)<<endl;
    cout << "Insert(23): " << tab.insert(23)<<endl;
    tab.print(); 

}