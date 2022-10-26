#include <bits/stdc++.h>

using namespace std;

class Vector
{
public:
    string anam;
    Vector() = default;
    Vector(string k)
    {
        anam = k;
    }
    Vector fun()
    {
        return Vector("as");
    }
};

int main()
{
    Vector v;
    cout << v.fun().anam;
}