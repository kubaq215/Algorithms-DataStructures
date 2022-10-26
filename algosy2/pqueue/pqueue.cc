

#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <typename T>
class PQueue
{
    struct Element
    {
        int prr = -100;
        T key;
    };

    int noe = 0;
	int size = 10;
    Element a;
    vector<Element> tab = {a,a,a,a,a,a,a,a,a,a};

public:

    void enqueue(T value, int priority);
    T front();
    T dequeue();
    void heapify(int i);
    void print();
};

template <typename T>
void PQueue<T>::enqueue(T value, int priority)
{
    if(noe+1 > size)
    {
        size *= 2;
        tab.resize(size);
    }
    tab[noe].key = value;
    tab[noe].prr = priority;
    noe++;
    
    int i = noe - 1;
    while(i != 0 && tab[(i-1)/2].prr < tab[i].prr)
    {
        Element tmp = tab[(i-1)/2];
        tab[(i-1)/2] = tab[i];
        tab[i] = tmp;
        i = (i-1)/2;
    }
}

template <typename T>
T PQueue<T>::front()
{
    if(noe == 0)
    {
        try
        {
            throw logic_error("Queue is empty");
        }
        catch(const logic_error& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
        return 0;
    }
    return tab[0].key;
}

template <typename T>
T PQueue<T>::dequeue()
{
    if(noe == 0)
    {
        try
        {
            throw logic_error("Queue is empty");
        }
        catch(const exception& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
        return 0;
    }

    T ans = tab[0].key;
    tab[0] = tab[noe];
    noe--;
    // heapify(0);
    int i = 0, k = 0;
    while((2*i+1) < noe)
    {
        int left = 2*i+1;
		int right = 2*i+2;

		if(tab[left].prr > tab[right].prr) k = left;
		else k = right;
		
		if(tab[i].prr > tab[k].prr)
			break;

		Element tmp = tab[i];
		tab[i] = tab[k];
		tab[k] = tmp;
		i = k;
    }
    cout << "o";
    return ans;
}

template <typename T>
void PQueue<T>::print()
{   
    int i = 0;
    std::cout << "Priority Queue:  ";
	while (i < noe) {
		std::cout << tab[i].key << " ";
		i++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

template <typename T>
void PQueue<T>::heapify(int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int biggest = i;
    if (l < size && tab[l].prr > tab[i].prr)
        biggest = l;
    if (r < size && tab[r].prr > tab[biggest].prr)
        biggest = r;
    if (biggest != i)
    {
        Element tmp = tab[i];
		tab[i] = tab[biggest];
		tab[biggest] = tmp;
        heapify(biggest);
    }
}

int main()
{
    PQueue<int> p;
    p.enqueue(3,3);
    p.enqueue(2,2);
    p.enqueue(1,1);
    p.enqueue(5,5);
    p.enqueue(4,4);
    p.enqueue(6,6);
    p.enqueue(0,0);
    p.enqueue(7,7);
    p.enqueue(8,8);
    p.enqueue(-1,-1);
    p.print();
    for(int i=0; i<10; i++)
    {
        cout << p.dequeue() << " ";
    }
}