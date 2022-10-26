double sum, Min, minsum;
Graph::vertex_iter start;
vector<int> path;
bool f;

static void InitVars(Graph::vertex_iter v)
{
    sum = v->price; 
    Min = v->price; 
    minsum = INFINITY;
    start = v;
    f = 0;
    path.clear();
}

double DFS(Graph *g, Graph::vertex_iter v, bool *visited, double cost, vector<int> &parent)
{
    visited[v.getk()] = 1;
    for(auto i = v.outedges_begin(); i != v.outedges_end(); ++i) 
    {
        if(v == start) f = 1;
        if(f)
        {
            path.push_back(v.getk());
            sum -= Min;
            if(v->price < Min)
                Min = v->price;
            sum += cost + Min;
        }
        if(i.destination() == start)
        {
            sum += i->weight;
            if(sum < minsum)
            {
                minsum = sum;
                path.push_back(i.destination().getk());
                parent = path;
            }
            else path.clear();
            sum = start->price;
            f = 0;
        }
        if(!visited[i.destination().getk()])
            DFS(g, i.destination(), visited, i->weight, parent);
    }
    visited[v.getk()] = 0;
    if(minsum > start->price)
    {
        parent.clear();
        parent.push_back(start.getk());
    }
    if(minsum != INFINITY && minsum < start->price) return minsum;
    return start->price;
}