#include <bits/stdc++.h> 
using namespace std; 

// Тип для пары целых чисел 
typedef pair<int, int> iPair; 

struct Graph 
{ 
	int V, E; 
	vector< pair<int, iPair> > edges; 

	Graph(int V, int E) 
	{ 
		this->V = V; 
		this->E = E; 
	} 

	// Вспомогательная функция для добавления ребра с весом w
	void addEdge(int u, int v, int w) 
	{ 
		edges.push_back({w, {u, v}});
		edges.push_back({w, {v, u}}); 
	} 

	// Поиск минимального покрывающего дерева
	int kruskalMST(); 
}; 

// Непересекающиеся множества вершин (компонент связности) графа
struct DisjointSets 
{ 
	int *parent, *rnk; 
	int n; 

	//Создать n одноэлементных множеств
	DisjointSets(int n) 
	{ 
		this->n = n; 
		parent = new int[n+1]; 
		rnk = new int[n+1]; 

		for (int i = 0; i <= n; i++) 
		{ 
			rnk[i] = 0; 
            //Каждый элемент - это его же родитель
			parent[i] = i; 
		} 
	} 

	//Какое множество содержит u?
	int find(int u) 
	{ 
		//без сжатия пути
		while (u != parent[u])
			u = parent[u];
		return u;
		/*
		//Сжатие пути
		if (u != parent[u]) 
			parent[u] = find(parent[u]); 
		return parent[u]; 
		*/
	} 

	// Объединить множества, содержащие x и y
	void merge(int x, int y) 
	{ 
		x = find(x);
        y = find(y); 
		//если x == y, ничего делать не нужно
		if (x == y)
			return;
		//иначе
		if (rnk[x] > rnk[y]) 
			parent[y] = x; 
		else // rnk[x] <= rnk[y] 
			parent[x] = y; 

		if (rnk[x] == rnk[y]) 
			rnk[y]++; 
	} 
}; 

// Поиск минимального покрывающего дерева
int Graph::kruskalMST() 
{ 
	int mst_wt = 0; // Начальный вес

	// Сортировка вершин по возрастанию веса
	sort(edges.begin(), edges.end()); 

	// Создать непересекающиеся множества для всех вершин
	DisjointSets ds(V); 

	// Проход по всем ребрам графа по порядку
	vector< pair<int, iPair> >::iterator it; 
	for (it=edges.begin(); it!=edges.end(); it++) 
	{ 
		int u = it->second.first; 
		int v = it->second.second; 

		int set_u = ds.find(u); 
		int set_v = ds.find(v); 

		// Проверка на цикл
		if (set_u != set_v) 
		{ 
			// Вершина попадает входит в минимальное дерево
			cout << u << " - " << v << endl; 
			mst_wt += it->first; 
			// Объединяем множества
			ds.merge(set_u, set_v); 
		}
	} 
	cout << endl; 
	return mst_wt; 
} 

int main() 
{ 
	int V = 6, E = 9; 
	Graph g(V, E); 

	// вершина, вершина, вес
	g.addEdge(0, 1, 2); 
	g.addEdge(0, 2, 1); 
	g.addEdge(1, 2, 2); 
	g.addEdge(2, 3, 2); 
	g.addEdge(1, 3, 1); 
	g.addEdge(2, 4, 3); 
	g.addEdge(3, 4, 3); 
	g.addEdge(3, 5, 4); 
	g.addEdge(4, 5, 2); 

	cout << "Ребра минимального покрывающего дерева: " << endl; 
	int mst_wt = g.kruskalMST(); 
	cout << "Вес минимального покрывающего дерева = " << mst_wt; 
	return 0; 
} 
