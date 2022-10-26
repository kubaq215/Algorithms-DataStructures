#include <bits/stdc++.h>
#include "set.hpp"
using namespace std;


int main()
{
    Set<int> s1, s2;
    for(int i=0; i<6; i++)
    {
        s1.insert(i);
        s2.insert(i+3);
    }
    s1.insert(10);
    // s2.insert(-1);
    s2.insert(11);
    s1.remove(3);
    cout << s1.contains(2) << endl;
    cout << s1.contains(3) << endl;
    cout << "Set 1: ";
    s1.print();
    cout << "Set 2: ";
    s2.print();
    s1.Union(s2);
    s1.intersection(s2);
    s1.difference(s2);
}