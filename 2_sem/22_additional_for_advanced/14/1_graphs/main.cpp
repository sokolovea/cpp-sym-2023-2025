#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<double>> adjMatrix;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix.resize(numVertices, vector<double>(numVertices, 0));
    }

    void addArc(int src, int dest)
    {
        adjMatrix[src][dest] = 1;
    }

    void removeArc(int src, int dest)
    {
        adjMatrix[src][dest] = 0;
    }

    void addEdge(int src, int dest)
    {
        addArc(src, dest);
        addArc(dest, src);
    }

    void removeEdge(int src, int dest)
    {
        removeArc(src, dest);
        removeArc(dest, src);
    }

    void printMatrix()
    {
        cout << "Матрица смежности графа:" << endl;
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjList()
    {
        cout << "Список смежности графа" << endl;
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Список смежных вершин для узла " << i << ": ";
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    void DFSHelper(int v, vector<bool>& visited)
    {
        return;
    }

    void DFS(int startVertex)
    {
        return;
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> queue; //очередь вершин
        return;
    }

    void addRandomEdges(int numEdges)
    {
        int addedEdges = 0;
        srand(time(NULL));
        while (addedEdges < numEdges)
        {
            addedEdges++;
            int src = rand() % numVertices;
            int dest = rand() % numVertices;
            if (src != dest) {
                addEdge(src, dest);
            }
        }
    }

    vector<double> dijkstra(int startVertex)
    {
        vector<double> dist(numVertices, numeric_limits<double>::infinity());
        vector<bool> visited(numVertices, false);

        dist[startVertex] = 0;

        for (int count = 0; count < numVertices - 1; count++)
        {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < numVertices; ++v)
            {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != numeric_limits<double>::infinity()
                                                            && dist[u] + adjMatrix[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
        return dist;
    }

    int minDistance(const vector<double>& dist, const vector<bool>& visited)
    {
        double minDist = numeric_limits<double>::infinity();
        int minIndex = -1;

        for (int v = 0; v < numVertices; ++v)
        {
            if (!visited[v] && dist[v] <= minDist)
            {
                minDist = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
};

int main()
{
    Graph g(5); //10
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    // g.addRandomEdges(10);

    //Матрица смежности
    g.printMatrix();

    //Список смежности
    g.printAdjList();

    cout << "Обход в глубину с 0 вершины:" << endl;
    g.DFS(0);

    // cout << "Обход в ширину с 0 вершины:" << endl;
    // g.BFS(0);

    // cout << "Кратчайшее расстояние между 0 и 4 вершиной" << endl;
    // auto shortest = g.dijkstra(0);
    // cout << shortest[4] << endl;
    return 0;
}
