#include <bits/stdc++.h>
#include "set.hpp"
using namespace std;


int main()
{
    Set<int> s1, s2;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(50);
    s2.insert(1);
    s2.insert(2);
    s2.insert(3);
    s1.print();
    s2.print();
    s1.difference(s2);
}