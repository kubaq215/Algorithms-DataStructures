#include <bits/stdc++.h>

using namespace std;


class List
{
private:

    class Node
    {
    public:
        int key{};
        Node *next{};
        Node *prev{};

        Node(int k) : key{k}, next{nullptr}, prev{nullptr} {}
    };

    Node *head;
    int noe = 0;

public:

    List() : head{nullptr} {}
    List(const List&);

    bool isEmpty()
    {
        return head == nullptr;
    }

    void add(int n);
    void addOn(int n, int pos);
    void contains(int n);
    void remove(int n);
    void removeOn(int pos);
    void sort();
    void print();
};

void List::print()
{
    Node *temp = head;
    while(temp)
    {
        cout << temp->key << "->";
        temp = temp->next;
    }
    cout << endl;
}

void List::add(int n)
{
    if(isEmpty())
    {
        head = new Node{n};
    }
    else
    {
        Node *temp = head;
        while(temp->next)
            temp = temp->next;
        Node *p = new Node{n};
        temp->next = p;
        p->prev = temp;
    }
    cout << "\nDodano element o wartosci " << n << endl;
    print();
    noe++;
}

void List::addOn(int n, int pos)
{
    if(pos > noe+1 || pos <=0)
    {
        cout << "\nWybrana pozycja znajduje się poza lista" << endl;
    }
    else
    {
        if(pos == noe+1)
        {
            Node *temp = head;
            while(temp->next)
                temp = temp->next;
            Node *p = new Node{n};
            temp->next = p;
            p->prev = temp;
        }
        else if(pos == 1)
        {
            Node *p = new Node{n};
            p->next = head;
            head->prev = p;
            head = p;
        }
        else
        {
            int i = 1;
            Node *temp = head;
            while(temp->next)
            {
                i++;
                if(i == pos)
                {
                    Node *p = new Node{n};
                    Node *k = temp->next;
                    p->next = k;
                    k->prev = p;
                    temp->next = p;
                    break;
                }
                temp = temp->next;
            }
        }
        cout << "\nDodano element o wartosci " << n << " na pozycje " << pos << endl;
        print();
        noe++;
    }
}

void List::contains(int n)
{
    Node *temp = head->next;
    bool o = 0;
    while(temp)
    {
        if(temp->key == n) 
        {
            cout << "\nLista zawiera element " << n << endl;
            o = 1;
            break;
        }
        temp = temp->next;
    }
    if(!o) cout << "\nLista nie zawiera elementu " << n << endl;
}

void List::remove(int n)
{
    Node *temp = head;
    bool o = 0;
    if(head->key == n)
    {
        head = head->next;
        head->prev = nullptr;
        o = 1;
        noe--;
    }
    else
    {
        while(temp)
        {
            Node *k = temp->next;
            if(k->key == n) 
            {
                Node *k2 = k->next;
                temp->next = k2;
                k2->prev = temp;
                o = 1;
                delete k;
                noe--;
                break;
            }
            temp = temp->next;
        }
    }
    if(!o) cout << "\nLista nie zawiera elementu " << n << endl;
    else 
    {
        cout << "\nUsunieto element o wartosci " << n << endl;
        print();
    }
}

void List::removeOn(int pos)
{
    if(pos > noe || pos <=0)
    {
        cout << "\nWybrana pozycja znajduje się poza lista" << endl;
    }
    else
    {
        int i = 1;
        if(pos == 1)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if(pos == noe)
        {
            Node *temp = head;
            while(temp)
            {
                i++;
                Node *k = temp->next;
                if(i == pos)
                {
                    temp->next = nullptr;
                    delete k;
                    break;
                }
                temp = temp->next;
            }
        }
        else
        {
            Node *temp = head;
            while(temp)
            {
                i++;
                Node *k = temp->next;
                if(i == pos)
                {
                    Node *k2 = k->next;
                    temp->next = k2;
                    k2->prev = temp;
                    delete k;
                    break;
                }
                temp = temp->next;
            }
            
        }
        cout << "\nUsunieto element na pozycji nr " << pos << endl;
        print();
        noe--;
    }
}

int compare(const void *p1, const void *p2)
{
    int d1 = *(int *)p1;   
    int d2 = *(int *)p2;
    return d1 - d2;
}

void List::sort()
{
    int *tab = new int [noe];
    Node *temp = head;
    int i = 0;
    while(temp)
    {
        tab[i] = temp->key;
        temp = temp->next;
        i++;
    }
    qsort(tab, noe, sizeof(int), compare);
    temp = head;
    i = 0;
    while(temp)
    {
        temp->key = tab[i];
        temp = temp->next;
        i++;
    }

    cout << "\nLista została posortowana" << endl;
    print();
}

int main() 
{
    List l{};
    l.add(20);
    l.add(17);
    l.add(11);
    l.add(2);
    l.remove(17);
    l.removeOn(2);
    l.add(13);
    l.add(3);
    l.remove(20);
    l.removeOn(2);
    l.add(-5);
    l.removeOn(1);
    l.addOn(23, 3);
    l.addOn(12, 2);
    l.add(15);
    l.addOn(14, 2);
    l.add(16);
    l.sort();
    l.remove(15);
     l.remove(-5);
    l.removeOn(2);
    l.removeOn(3);
    l.removeOn(1);
    l.add(-10);
    l.add(2);
    l.removeOn(4);
    l.addOn(12, 3);
    l.removeOn(3);
     l.add(4);
    l.removeOn(0);
    l.removeOn(6);
    l.addOn(32, 3);
    l.addOn(20, 5);
    l.addOn(18, 0);
    l.removeOn(3);
    l.removeOn(4);
    l.add(11);
    l.sort();
    l.contains(11);
    l.contains(100);
}
