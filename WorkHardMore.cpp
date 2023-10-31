#include<iostream>
#include <vector>
#include <string>
using namespace std;



class Graph
{
private:
	double** adj_matrix;
	int size;
public:
	Graph(int size);
	~Graph(void);
	int V();
	int E();
	void add(int x, int y, double value);
	void remove(int x, int y);
};
Graph::Graph(int size)
{
	this->size = size;
	this->adj_matrix = new double* [size];
	for (int i = 0; i < size; i++)
		this->adj_matrix[i] = new double[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				adj_matrix[i][j] = 0.0;
			else
				adj_matrix[i][j] = -1.0;
		}
}
// destructing internal structures
Graph::~Graph(void)
{
	for (int i = 0; i < size; i++)
		delete[] adj_matrix[i];
	delete[] adj_matrix;
}
// returns number of vertices
inline int Graph::V()
{
	return this->size;
}
// returns number of edges
int Graph::E()
{
	int count = 0;

	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (adj_matrix[i][j] > -1.0)
				count++;
	return count;
}
// adding an edge between x and y with distance value
void Graph::add(int x, int y, double value)
{
	if (x == y)
		return;
	adj_matrix[x][y] = value;
	adj_matrix[y][x] = value;
}
// removing edge from x to y
void Graph::remove(int x, int y)
{
	if (x == y)
		return;
	adj_matrix[x][y] = -1;
	adj_matrix[y][x] = -1;
}










int main()
{
	setlocale(LC_ALL, "Russian");
	vector <vector <int>> matrix(7, vector <int>(7));
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << "Вершины " << i + 1 << " и " << j + 1 << " Связаны? Y/N ";
			string ans;
			cin >> ans;
			if (ans == "Y")
			{
				matrix[i][j] = 1;
			}
			else 
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		for (int j = 0; j < 6; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}

	return 0;
}


