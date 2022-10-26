#include <bits/stdc++.h>

using namespace std;

struct poly
{
    int wsp = 0;
};

class wielomian
{
private:

    poly *tab;
    int stopien;

public:

    wielomian() = default;
    void wprowadz();
    void dodaj(wielomian &W);
    void odejmij(wielomian &W);
    void pomnoz(wielomian &W);
    void policz(double x);
    void wypisz();
};

void wielomian::wypisz()
{
    bool k = 0;
    for(int i=0; i<stopien+1; i++)
    {
        if(tab[i].wsp)
        {
            cout << tab[i].wsp << "x^" << i;
            k = 1;
        }
        if(i != stopien && tab[i+1].wsp > 0 && k)
            cout << "+";
    }
}

void wielomian::wprowadz()
{
    cout << "Wprowadz stopien wielomianu - ";
    cin >> stopien;
    cout << endl;
    tab = new poly [stopien+1];
    int n;
    char g;
    do
    {
    cin.clear();
    cout << "podaj potege: ";
    cin >> n;
    cout << "podaj wspolczynnik: ";
    cin >> tab[n].wsp;

    cout << "\nTwoj wielomian - ";
    wypisz();

    cout << "\n\nstop? [Y,n] ";
    cin >> g;
    cout << "-------------------------------" << endl;
    }
    while(g != 'y' && g != 'Y');
}

void wielomian::dodaj(wielomian &W)
{
    wypisz();
    cout << " + ";
    W.wypisz();
    cout << " = ";

    if(W.stopien <= this->stopien)
    {
        for(int i=0; i<W.stopien+1; i++)
            tab[i].wsp += W.tab[i].wsp;
    }
    else
    {
        poly *tab2 = new poly [W.stopien + 1];

        for(int i=0; i<W.stopien+1; i++)
            tab2[i].wsp = tab[i].wsp + W.tab[i].wsp;
        tab = tab2;
        stopien = W.stopien;
    }

    wypisz();
    cout << endl << endl;
}

void wielomian::odejmij(wielomian &W)
{
    wypisz();
    cout << " - ";
    W.wypisz();
    cout << " = ";

    if(W.stopien <= this->stopien)
    {
        for(int i=0; i<W.stopien+1; i++)
            tab[i].wsp -= W.tab[i].wsp;
    }
    else
    {
        poly *tab2;
        tab2 = (poly*) realloc(tab, (W.stopien+1) * sizeof(poly));
        tab = tab2;
        for(int i=0; i<W.stopien+1; i++)
            tab[i].wsp -= W.tab[i].wsp;
        stopien = W.stopien;
    }

    wypisz();
    cout << endl << endl;
}

void wielomian::pomnoz(wielomian &W)
{
    wypisz();
    cout << " * ";
    W.wypisz();
    cout << " = ";

    poly *prod = new poly [stopien + W.stopien + 1];

    for(int i=stopien; i>=0; i--)
        for(int j=W.stopien; j>=0; j--)
            if(tab[i].wsp && W.tab[j].wsp)
                prod[i+j].wsp += tab[i].wsp * W.tab[j].wsp;

    tab = prod;
    stopien += W.stopien;
    wypisz();
    cout << endl << endl;
}

void wielomian::policz(double x)
{
    double result = tab[stopien].wsp;

    for(int i=stopien-1; i>=0; i--)
            result = result * x + tab[i].wsp;

    cout << "Wartosc wielomianu ";
    wypisz();
    cout << " w punkcie " << x << " wynosi " << result << endl << endl;
}

int main()
{
    wielomian l, n;
    l.wprowadz();
    n.wprowadz();
    l.dodaj(n);
    l.odejmij(n);
    l.pomnoz(n);
    l.policz(1);
    l.policz(2);
}