#include <bits/stdc++.h>
#include "graphz3.hpp"

Graph::vertex_iter get_iter(Graph *g, int id)
{
    auto v_iter = g->vertices_begin();
    for(int i=0; i<id; i++)
        ++v_iter;
    return v_iter;
}

// do tworzenia labiryntu wzoruje sie na algorytmie Prima
void create_Maze(Graph *g, int height, int width)
{
    srand(time(NULL));
    vector<int> in_path;
    int size = height * width; // liczba wszystkich wierzcholkow
    vector<bool> visited(size);
    int cell = rand() % size; // losujemy pozycje startowa
    in_path.push_back(cell);
    // powtarzamy az liczba wierzchołkow nalezacych do sciezki bedzie rowna liczbie wszystkich 
    while(in_path.size() != size) 
    {
        visited[cell] = 1;
        vector<int> neighbors; // tworzymy tablice dla sasiadow danej komorki

        // dodajemy do niej komorki z prawej i lewej jesli mozna i jesli nie sa juz w sciezce
        if(cell % width != width - 1 && !visited[cell + 1])
        {
            neighbors.push_back(cell + 1);
        }
        else if(cell % width != 0 && !visited[cell - 1])
        {
            neighbors.push_back(cell - 1);
        }

        // tak samo z gory i z dolu
        if(cell / width != height - 1 && !visited[cell + width])
        {
            neighbors.push_back(cell + width);
        }
        else if(cell / width != 0 && !visited[cell - width])
        {
            neighbors.push_back(cell - width);
        }

        if(!neighbors.empty())
        {
            int randID = rand() % neighbors.size(); // losujemy indeks sasiada ktory trafi do sciezki
            auto v1_it = get_iter(g, cell);
            auto v2_it = get_iter(g, neighbors[randID]);
            g->connect(v1_it, v2_it);
            g->connect(v2_it, v1_it);
            in_path.push_back(neighbors[randID]); // dodajemy do sciezki
            visited[neighbors[randID]] = 1;
        }
        int k = rand() % in_path.size(); // losujemy kolejna komorke z tych ktore sa juz w sciezce
        cell = in_path[k]; 
    }
}

void print_Maze(Graph *g, int height, int width)
{
    int h = height * 2 + 1;
    int d = width * 2 + 1;

    for(int i=0; i<h; i++)
    {
        int index = 0;
        for(int j=0; j<d; j++)
        {
            // gorna i dolna sciana
            if(i == 0 || i == h-1)
            {
                if(j%2 == 0) cout << "+";
                else cout << "-";
            }
            // lewa i prawa sciana
            else if(j == 0 || j == d-1) 
            {
                if(i%2 == 1) cout << "|";
                else cout << "+";
            }
            // na nieparzystych poziomach mamy spacje w kazdej komorce
            // dodatkowo sprawdzamy czy dwie komorki sa polaczone poziomo
            // jesli tak to dajemy spacje pomiedzy nimi a jesli nie to sciane "|"
            else if(i%2 == 1)
            {
                if(j%2 == 0)
                {
                    auto v1_it = get_iter(g, (width * (i/2)) + index);
                    auto v2_it = get_iter(g, (width * (i/2)) + index + 1);
                    if(g->are_connected(v1_it, v2_it)) cout << " ";
                    else cout << "|";
                    index++;
                }
                else cout << " ";
            }
            // na parzystych sprawdzamy czy komorka powyzej jest polaczona z ta ponizej
            // jesli tak to dajemy spacje jesli nie to sciane "-"
            // dodatkowo pomiedzy przejsciami i scianami dajemy "+"
            else
            {
                if(j%2 == 1)
                {
                    auto v1_it = get_iter(g, (width * ((i-1)/2)) + index);
                    auto v2_it = get_iter(g, (width * ((i-1)/2)) + index + width);
                    if(g->are_connected(v1_it, v2_it)) cout << " ";
                    else cout << "-";
                    index++;
                }
                else cout << "+";
            }
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    int h = stoi(argv[1]), w = stoi(argv[2]);
    Graph g(h * w);
    create_Maze(&g, h, w);
    print_Maze(&g, h, w);
    delete &g;
}