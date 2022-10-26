#ifndef BITSET_HPP
#define BITSET_HPP

#include <bits/stdc++.h>

using namespace std;

template <int MIN, int MAX>
class BitSet
{
private:

    int size = ceil((double)(MAX - MIN)/8);
    unsigned char *tab = (unsigned char*) calloc(size, 1);
    
public:

    void insert(int value);
    void remove(int value);
    bool contains(int value);
    void Union(const BitSet &other);
    void intersection(const BitSet &other);
    void difference(const BitSet &other);
};

template <int MIN, int MAX>
void BitSet<MIN,MAX>::insert(int value)
{
    if(value > MAX || value < MIN)
    {
        try
        {
            throw logic_error("Value is out of bounds");
        }
        catch(const exception& e)
        {
            std::cerr << "Cought: " << e.what() << endl;
        }
        return;
    }
    int pos = (value - MIN) / 8;
    int k = (value - MIN) % 8;
    tab[pos] = tab[pos] | (1 << k);
}

template <int MIN, int MAX>
void BitSet<MIN,MAX>::remove(int value)
{
    if(value > MAX || value < MIN) return;
    int pos = (value - MIN) / 8;
    int k = (value - MIN) % 8;
    tab[pos] = tab[pos] & (255 - (1 << k));
}

template <int MIN, int MAX>
bool BitSet<MIN,MAX>::contains(int value)
{
    if(value > MAX || value < MIN) return 0;
    int pos = (value - MIN) / 8;
    int k = (value - MIN) % 8;
    return tab[pos] & (1 << k);
}

template <int MIN, int MAX>
void BitSet<MIN,MAX>::Union(const BitSet &other)
{
    for(int i=0; i<size; i++)
        tab[i] |= other.tab[i];
}

template <int MIN, int MAX>
void BitSet<MIN,MAX>::intersection(const BitSet &other)
{
    for(int i=0; i<size; i++)
        tab[i] &= other.tab[i];
}

template <int MIN, int MAX>
void BitSet<MIN,MAX>::difference(const BitSet &other)
{
    for(int i=0; i<size; i++)
        tab[i] &= ~other.tab[i];
}

#endif