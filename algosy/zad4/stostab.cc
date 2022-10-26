#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:

    int *tab = (int*) malloc(sizeof(int));
    int noe = 0;

public:

    Stack() = default;

    void push(int k);
    void pop();
    void peek();
    bool isEmpty();
    void size();

    void resize()
    {
        int *more_elements;
        more_elements = (int*) realloc(tab, (noe+1) * sizeof(int));
        tab = more_elements;
    }
};

void Stack::push(int k)
{
    tab[noe] = k;
    noe++;
    resize();
    cout << "Dodano wartosc " << k << endl;
}

void Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stos jest pusty" << endl;
        return;
    }

    cout << "Zdjeto element ktory mial wartosc " << tab[noe-1] << endl;
    noe--;
}

void Stack::peek()
{
    if(not isEmpty())
    {
        cout << "Wartosc na wierzchu wynosi " << tab[noe-1] << endl;
    }
    else
    {
        cout << "Nie ma na co patrzec" << endl;
    }
}

bool Stack::isEmpty()
{
    return !noe;
}

void Stack::size()
{
    cout << "Stos ma wielkosc " << noe << endl;
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
    st.pop();
    st.size();
}