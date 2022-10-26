#include <bits/stdc++.h>
#include <time.h>
#include <fstream>

using namespace std;

unsigned long k = 0, l = 1;

void swaps(double a[], int i, int j)
{
	double temp;
  	if (i != j) 
  	{
    	temp = a[i];
    	a[i] = a[j];
    	a[j] = temp; 
  	}
}

void bubblesort(double a[], int n)
{
    int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
        {
			if(a[j] > a[j+1])
            {
                swaps(a, j, j+1);
                k+=2;
            }
            else k++;
        }		
}

void quicksort(double a[], int left, int right)
{
    int i, last;

	if(right <= left) return;
    l++;
	int sr = (right + left)/2;
    l++;
	swaps(a, left, sr);
    l++;
	last = left;
    l++;
	for (i=left+1; i<=right; i++)
    {
     	if (a[i] < a[left])
        {
       		swaps(a, ++last, i);
            l+=2;
        }
        else l++;
    }
	swaps(a, left, last);
    l++;
   	quicksort(a, left, last-1);
   	quicksort(a, last+1, right);
}

int main()
{
    ofstream out1, out2;
    out1.open("qdata.txt", ofstream::out | ofstream::ate | ofstream::trunc);
    out2.open("bdata.txt", ofstream::out | ofstream::ate | ofstream::trunc);
    double *tab1, *tab2;
    srand(time(NULL));
    for(int j=1; j<=5; j++)
    {
        out1 << "\n\n\n\n\n\n----------------------------------------------\n\n\n\n\n\n";
        out2 << "\n\n\n\n\n\n----------------------------------------------\n\n\n\n\n\n";
        for(int r=1; r<=60; r++)
        {
            int q = 10*r;
            tab1 = new (nothrow) double [q];
            tab2 = new (nothrow) double [q];
            if(tab1 == nullptr || tab2 == nullptr)
                cout << "Blad alokacji pamieci";
            

            for(int i=0; i<q; i++)
            {
                tab1[i] = rand() % (5*q);
                tab2[i] = tab1[i];
            }

            quicksort(tab1, 0, q-1);
            bubblesort(tab2, q);
            out1 << q << "      " << l << endl;
            out2 << q << "      " << k << endl;
            k = 0;
            l = 1;
        }
    }
    out1.close();
    out2.close();
}