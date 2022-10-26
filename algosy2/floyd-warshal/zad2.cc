#include <bits/stdc++.h>
#include "graphz2.hpp"

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
    while(a != b)
    {
        double price;
        in >> price;
        in.ignore();
        a->price = price;
        ++a;
    }
    int id1, id2;
    double cost;
    while(in >> id1 >> id2 >> cost)
    {
        Graph::vertex_iter i1(id1-1, &g), i2(id2-1, &g);
        auto edge = g.connect(i1, i2);
        edge->weight = cost;
        in.ignore();
    }
    
    in.close();
    return g;
}

void Floyd_Warshall(Graph *g, vector<vector<double>> &d, vector<vector<int>> &parent)
{
    for(auto v1_iter = g->vertices_begin(); v1_iter != g->vertices_end(); ++v1_iter)
    {
        for(auto v2_iter = g->vertices_begin(); v2_iter != g->vertices_end(); ++v2_iter)
        {
            d[v1_iter.getk()][v2_iter.getk()] = INFINITY;
            parent[v1_iter.getk()][v2_iter.getk()] = -1;
        }
        d[v1_iter.getk()][v1_iter.getk()] = 0;
        parent[v1_iter.getk()][v1_iter.getk()] = v1_iter.getk();
    }
    for(auto edge_iter = g->edges_begin(); edge_iter != g->edges_end(); ++edge_iter)
    {
        d[edge_iter.source().getk()][edge_iter.destination().getk()] = edge_iter->weight;
        parent[edge_iter.source().getk()][edge_iter.destination().getk()] = edge_iter.source().getk();
    }
    for(auto u_iter = g->vertices_begin(); u_iter != g->vertices_end(); ++u_iter)
        for(auto v1_iter = g->vertices_begin(); v1_iter != g->vertices_end(); ++v1_iter)
            for(auto v2_iter = g->vertices_begin(); v2_iter != g->vertices_end(); ++v2_iter)
                if(d[v1_iter.getk()][v2_iter.getk()] > d[v1_iter.getk()][u_iter.getk()] + d[u_iter.getk()][v2_iter.getk()])
                {
                    d[v1_iter.getk()][v2_iter.getk()] = d[v1_iter.getk()][u_iter.getk()] + d[u_iter.getk()][v2_iter.getk()];
                    parent[v1_iter.getk()][v2_iter.getk()] = parent[u_iter.getk()][v2_iter.getk()];
                }
}

int main(int argc, char *argv[])
{
    Graph g = load(argv[1]);
    int n = g.vertex_count();

    const double CUSTOMS = 0.5;

    vector<vector<int>> parent(n, vector<int>(n));
    vector<vector<double>> d(n, vector<double>(n));
    Floyd_Warshall(&g, d, parent);

    auto iter = g.vertices_begin();
    auto e = g.vertices_end();
    int i=0;
    while(iter != e)
    {
        
        double min = iter->price * CUSTOMS;
        auto j_iter = g.vertices_begin();
        int ver = i;
        for(int j=0; j<n; j++)
        {
            if(d[i][j] != INFINITY && d[j][i] != INFINITY)
            {
                double sum = d[i][j] + j_iter->price * CUSTOMS + d[j][i];
                if(sum < min)
                {
                    min = sum;
                    ver = j;
                }
            }
            ++j_iter;
        }

        stack<int> st;
        cout << i+1 << " (cło: " << iter->price * CUSTOMS << " d/lb) : ";

        int par1 = ver;
        while(par1 != i)
        {
            par1 = parent[i][par1];
            st.push(par1);
        }
        while(!st.empty()) 
        {
            cout << st.top()+1 << "-";
            st.pop();
        }
        int par = i;
        while(ver != par)
        {
            par = parent[ver][par];
            st.push(par);
        }
        while(!st.empty()) 
        {
            cout << st.top()+1<< "-";
            st.pop();
        }
        i++;
        cout << i << " (cło i reagenty: " << min << " d/lb)" << endl;
        ++iter;
    }
}