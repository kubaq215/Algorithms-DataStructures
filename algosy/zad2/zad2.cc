#include <bits/stdc++.h>

using namespace std;

struct Element
{
    int value;
    int next;
};

int compare(const void *p1, const void *p2)
{
    struct Element d1 = *(struct Element *)p1;   
    struct Element d2 = *(struct Element *)p2;
    return d1.value - d2.value;
}

struct List
{
    int size = 1, noe = 0;
    Element *elements = (Element*) malloc(size*sizeof(Element));
    
    void print()
    {
        for(int i=1; i<=noe; i++)
            cout << elements[i].value << "->";
            cout << endl;
        // for(int i=1; i<=noe; i++)
        //     cout << "{" << elements[i].value << ", " << elements[i].next << "}";
        //     cout << endl;
    }

    void resize()
    {
        Element *more_elements;
        more_elements = (Element*) realloc(elements, (size+1) * sizeof(Element));
        elements = more_elements;
        size++;
    } 

    void downsize(int pos)
    {
        Element *less_elements = (Element*) malloc((size-1)*sizeof(Element));
        int k = 0;
        for(int i=0; i<=noe; i++)
            if(i != pos)
            {
                less_elements[k] = elements[i];
                elements[k] = less_elements[k];
                k++;
            }
        noe--;
        size--;
    }

    void add(int n)
    {
        resize();
        elements[noe + 1].value = n;
        elements[noe + 1].next = -1;
        elements[noe].next = noe + 1;
        noe++;
    
        cout << "\nDodano element o wartosci " << n << endl;
        print();
    }

    void addOn(int n, int pos)
    {
        if(pos <= noe+1 && pos > 0)
        {
            if(pos == noe+1)
                add(n);
            else
            { 
                resize();
                Element e[noe-pos+1];
                int j = 0;
                for(int i=pos; i<=noe; i++)
                {
                    e[j] = elements[i];
                    j++;
                }
                elements[pos].value = n;
                elements[pos].next = pos+1;
                j = 0;
                for(int i=pos+1; i<=noe+1; i++)
                {
                    elements[i] = e[j];
                    j++;
                    if(i != noe+1) elements[i].next = i+1;
                    else elements[i].next = -1;
                } 
                noe++;
                cout << "\nDodano element o wartosci " << n << " na pozycje " << pos << endl;
                print();
            }
        }
        else cout << "\nMiejsce znajduje sie poza lista" << endl;
    }

    void contains(int n)
    {
        int k = 0;
        bool p = 0;
        while(k!=-1)
        {
            k = elements[k].next;
            if(elements[k].value == n)
            {
                p = 1;
                break;
            }
        }
        if(p) cout << "\nLista zawiera element " << n << endl;
        else cout << "\nLista nie zawiera elementu " << n << endl;
    }

    void remove(int n)
    {
        int k = 0, a = 0 , z;
        bool p = 0, p1 = 0;
        while(k!=-1)
        {
            k = elements[k].next;
            if(elements[k].value == n)
            {
                
                int q = elements[k].next, w;
                if(q == k+1) 
                    elements[a].next = k;
                else 
                {
                    elements[a].next = elements[k].next - 1; 
                    p1 = 1;
                }
                downsize(k);
                if(!p1)
                {
                    while(q != -1)
                    {
                        w = elements[k].next;
                        if(w!=-1)
                        {
                            elements[k].next = q; 
                            k = q;
                            q = w;
                        }
                        else  
                        {
                            elements[k].next = -1;
                            break;
                        }
                    }
                }
                else
                {
                    elements[1].next -= 1;
                }
                p = 1;
                break;
            }            
            a = elements[a].next;
        }
        if(p)
        {
            cout << "\nUsunieto element o wartosci " << n << endl;
            
        }
        else cout << "\nNie ma takiego elementu" << endl;
        print();
    }

    void removeOn(int pos)
    {
        int k = 0, a = 0, i = 0;
        bool p = 0;
        if(pos <= noe && pos > 0)
        {
            while(k!=-1)
            {
                k = elements[k].next;
                i++;
                if(i == pos)
                {
                    
                    int q = elements[k].next, w;
                    elements[a].next = k;
                    downsize(k);
                    if(q == -1)
                        elements[a].next = -1;
                    while(q != -1)
                    {
                        w = elements[k].next;
                        if(w!=-1)
                        {
                            elements[k].next = q; 
                            k = q;
                            q = w;
                        }
                        else  
                        {
                            elements[k].next = -1;
                            break;
                        }
                    }
                    
                    
                    p = 1;
                    break;
                }
                // i++;
                a = elements[a].next;
            }
            if(p)
            {
                cout << "\nUsunieto element na pozycji nr " << pos << " w tablicy" << endl;
                
            }
            else cout << "\nNie istnieje pozycja nr " << pos << " w tablicy" << endl;
        }
        else cout << "\nMiejsce znajduje sie poza lista" << endl;
        print();
    }

    void sort()
    {
        Element *sorting = (Element*) malloc((noe)*sizeof(Element));

        for(int i=1; i<=noe; i++)
            sorting[i-1] = elements[i];

        qsort(sorting, noe, sizeof(Element), compare);

        for(int i=1; i<=noe; i++)
        {
            elements[i] = sorting[i-1];
            if(i == noe) elements[i].next = -1;
            else elements[i].next = i+1;
        }

        cout << "\nLista została posortowana" << endl;
        print();
    }
};


int main()
{
   
    List l;
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
    l.remove(15);
    // // l.sort();
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
    l.removeOn(2);
    l.removeOn(1);
    l.addOn(32, 3);
    l.addOn(20, 2);
    l.addOn(18, 1);
    l.removeOn(3);
    l.removeOn(4);
    l.add(11);
    for(int i=0; i<1000; i++)
    {
        l.add(i%6);
        l.add(i%17);
        l.add(i);
        l.remove((i+2)%11);
        l.remove(i%6);
    }
}

