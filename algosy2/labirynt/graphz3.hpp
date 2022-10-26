#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:

    class vertex 
    { 
        public: 
        string label; 
    };
    class edge { public: double weight; };

    struct pole
    {
        edge ed;
        bool jest = 0;
    };

    pole **tab;
    int size, noe = 0;
    vertex *v_list;

public:

    class inedge_iter;
    class outedge_iter;
    class edge_iter;
    class vertex_iter;

    Graph() = default;
    Graph(int vertex_count);
    ~Graph();
    int vertex_count();
    int edge_count();
    edge_iter connect(vertex_iter src, vertex_iter dst);
    void disconnect(vertex_iter src, vertex_iter dst);
    bool are_connected(vertex_iter src, vertex_iter dst);
    vertex_iter vertices_begin();
    vertex_iter vertices_end();
    edge_iter edges_begin();
    edge_iter edges_end();
    void print();
};
void Graph::print()
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            cout << tab[i][j].jest << " ";
        cout << endl;
    }
}

class Graph::vertex_iter
{
private:

    int k;
    Graph *g;

public:

    vertex_iter() = default;
    vertex_iter(int k1, Graph *g1) 
    { 
        g = g1;
        k = k1;
    }
    int getk() { return k; };
    bool operator==(vertex_iter other) { return other.k == k; }
    bool operator!=(vertex_iter other) { return other.k != k; }
    vertex_iter & operator++() 
    {
        vertex_iter &tmp = *this;
        k++;
        return tmp;
    }
    vertex & operator*() { return g->v_list[k]; }
    vertex * operator->() { return &(g->v_list[k]); }
    outedge_iter outedges_begin();
    outedge_iter outedges_end();
    inedge_iter inedges_begin();
    inedge_iter inedges_end();
};

class Graph::edge_iter
{
private:

    int i, j;
    Graph *g;

public:

    edge_iter(Graph *g1)
    {
        g = g1;
        for(i=0; i<g->size; i++)
            for(j=0; i<g->size; j++)
                if(g->tab[i][j].jest)
                    return;
    }
    edge_iter(int i1, int j1, Graph *g1)
    {
        g = g1;
        i = i1;
        j = j1;
    }
    bool operator==(edge_iter other) { return (other.i == i && other.j == j); }
    bool operator!=(edge_iter other) { return (other.i != i && other.j != j); }
    edge_iter & operator++()
    {
        edge_iter &tmp = *this;

        if(j+1 < g->size) j++;
        else if(i+1 < g->size) { j = 0; i++; }
        else { j++; i++; }

        for(; i<g->size; ++i)
        {
            for(; j<g->size; ++j)
                if(g->tab[i][j].jest)
                    return tmp;

            if(i+1 != g->size) j = 0;
        }
        return tmp;
    }
    edge & operator*() { return g->tab[i][j].ed; }
    edge * operator->() { return &(g->tab[i][j].ed); }
    vertex_iter source() { return vertex_iter(i, g); }
    vertex_iter destination() { return vertex_iter(j, g); }
};

class Graph::inedge_iter
{
private:

    int i, j;
    Graph *g;

public:

    inedge_iter(int j1, Graph *g1)
    {
        g = g1;
        j = j1;
        for(i=0; i<g->size; i++)
            if(g->tab[i][j].jest)
                return;
    }
    inedge_iter(int i1, int j1, Graph *g1)
    {
        g = g1;
        i = i1;
        j = j1;
    }
    bool operator==(inedge_iter other) { return (other.i == i && other.j == j); }
    bool operator!=(inedge_iter other) { return (other.i != i && other.j == j); }
    inedge_iter & operator++()
    {
        inedge_iter &tmp = *this;
        i++;
        for(; i<g->size; i++)
            if(g->tab[i][j].jest)
                return tmp;
        return tmp;
    }
    edge & operator*() { return g->tab[i][j].ed; }
    edge * operator->() { return &(g->tab[i][j].ed); }
    vertex_iter source() { return vertex_iter(i, g); }
    vertex_iter destination() { return vertex_iter(j, g); }
};

class Graph::outedge_iter
{
private:

    int i, j;
    Graph *g;

public:

    outedge_iter(int i1, Graph *g1)
    {
        g = g1;
        i = i1;
        for(j=0; i<g->size; j++)
            if(g->tab[i][j].jest)
                return;
    }
    outedge_iter(int i1, int j1, Graph *g1)
    {
        g = g1;
        i = i1;
        j = j1;
    }
    bool operator==(outedge_iter other) { return (other.i == i && other.j == j); }
    bool operator!=(outedge_iter other) { return (other.i == i && other.j != j); }
    outedge_iter & operator++()
    {
        outedge_iter &tmp = *this;
        j++;
        for(; j<g->size; j++)
            if(g->tab[i][j].jest)
                return tmp;
        return tmp;
    }
    edge & operator*() { return g->tab[i][j].ed; }
    edge * operator->() { return &(g->tab[i][j].ed); }
    vertex_iter source() { return vertex_iter(i, g); }
    vertex_iter destination() { return vertex_iter(j, g); }
};

Graph::inedge_iter Graph::vertex_iter::inedges_begin()
{
    return inedge_iter(k, g);
}

Graph::inedge_iter Graph::vertex_iter::inedges_end()
{
    return inedge_iter(g->size, k, g);
}

Graph::outedge_iter Graph::vertex_iter::outedges_begin()
{
    return outedge_iter(k, g);
}

Graph::outedge_iter Graph::vertex_iter::outedges_end()
{
    return outedge_iter(k, g->size, g);
}

Graph::Graph(int vertex_count)
{
    size = vertex_count;
    v_list = new vertex[size];
    tab = new pole*[size];
    for(int i=0; i<size; i++)
        tab[i] = new pole[size];
}

Graph::~Graph()
{
    for(int i=0; i<size; i++)
        delete tab[i];
    delete[] tab;
    delete[] v_list;
}

int Graph::vertex_count()
{
    return size;
}

int Graph::edge_count()
{
    return noe;
}

Graph::edge_iter Graph::connect(vertex_iter src, vertex_iter dst)
{
    int i = src.getk();
    int j = dst.getk();
    if(!tab[i][j].jest)
    {
        edge ed;
        tab[i][j].jest = 1;
        tab[i][j].ed = ed;
        noe++;
    }
    return edge_iter(i, j, this);
}

void Graph::disconnect(vertex_iter src, vertex_iter dst)
{
    int i = src.getk();
    int j = dst.getk();
    tab[i][j].jest = 0;
}

bool Graph::are_connected(vertex_iter src, vertex_iter dst)
{
    int i = src.getk();
    int j = dst.getk();
    if(tab[i][j].jest) return 1;
    return 0; 
}

Graph::vertex_iter Graph::vertices_begin()
{
    return vertex_iter(0, this);
}

Graph::vertex_iter Graph::vertices_end()
{
    return vertex_iter(size, this);
}

Graph::edge_iter Graph::edges_begin()
{
    return edge_iter(this);
}

Graph::edge_iter Graph::edges_end()
{
    return edge_iter(size, size, this);
}

#endif