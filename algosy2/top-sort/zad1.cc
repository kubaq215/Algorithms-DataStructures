#include <bits/stdc++.h>
#include "graph.hpp"

using namespace std;

Graph load(char *name)
{
    ifstream in;
    in.open(name);
    int n;
    in >> n;
    in.ignore();
    Graph g(n);
    auto a = g.vertices_begin();
    auto b =  g.vertices_end();
    int i = 0;
    while(a != b)
    {
        string k;
        getline(in, k);
        a->label = k;
        a->id = i;
        i++;
        ++a;
    }
    int id1, id2;
    while(in >> id1 >> id2)
    {
        Graph::vertex_iter i1(id1-1, &g), i2(id2-1, &g);
        g.connect(i1, i2);
        in.ignore();
    }
    
    in.close();
    return g;
}

int DFS(Graph::vertex_iter v, Graph *g, int counter)
{
    static int depth = 0;
    for(auto i = v.inedges_begin(); i != v.inedges_end(); ++i) 
        DFS(i.source(), g, counter+1);

    if(counter > depth) depth = counter;
    return depth;
}


int main(int argc, char *argv[])
{
    Graph g = load(argv[1]);
    string s = argv[2];
    auto i = g.vertices_begin();
    for(; i != g.vertices_end(); ++i)
        if(i->label == s)
            break;
    
    cout << DFS(i, &g, 1) << endl;;
    return 0;


    double d[n][n] //tablica która masz z tego floyda

    for(int i=0; i<n; i++)
    {
        double min = /*clo itego wierzchołka*/;
        for(int j=0; j<n; j++)
        {
            if(d[i][j] != INFINITY && d[j][i] != INFINITY)
            {
                double sum = d[i][j] + /*cło jotego wierzchołka*/ + d[j][i];
                if(sum < min)
                    min = sum;
            }
            // wypisujesz tam co trzeba wypisywać
        }

    }
}