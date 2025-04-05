#include <iostream>
#include <list>
using namespace std;
 
// Раскраска графа (ненаправленного)
class Graph
{
    int V;    // Кол-во вершин
    list<int> *adj;    // Список смежности
public:
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }
 
    void addEdge(int v, int w);
    void greedyColoring();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::greedyColoring()
{
    int result[V]; //номера цветов для каждой вершины графа
    // Массив доступных цветов
    bool available[V];
    result[0]  = 0;
 
    // Остальные вершины помечаются как нераскрашенные
    for (int u = 1; u < V; u++)
        result[u] = -1;
 
    for (int cr = 0; cr < V; cr++)
        available[cr] = true;
 
    // Назначение цветов
    for (int u = 1; u < V; u++)
    {
        // Обработка всех смежных вершин
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
 
        // Поиск первого доступного цвета
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr])
                break;
 
        result[u] = cr;
 
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
    }
  
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}
 
int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of graph\n";
    g1.greedyColoring();
 
    return 0;
}
