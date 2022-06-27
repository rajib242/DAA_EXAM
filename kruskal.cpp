#include <iostream>
using namespace std;
int parent[15];
int size[15];
void makeset(int i)
{
		parent[i] = i;
		size[i] = 0;
	
}
int findparent(int node)
{
	if (parent[node] == node)
		return node;
	else
		return parent[node] = findparent(parent[node]);
}
int Union(int u, int v)
{
	u = findparent(u);
	v = findparent(v);
	if (u != v)
	{

		if (size[u] < size[v])
			return parent[u] = v;
		else if (size[v] < size[u])
			return parent[v] = u;
		else
		{
			return parent[v] = u;
			size[u]++;
		}
	}
}

struct node
{
	int vertex1;
	int vertex2;
	int weight;
};
void sort(struct node jobs[], int n)
{
	struct node temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (jobs[i].weight > jobs[j].weight)
			{
				temp = jobs[j];
				jobs[j] = jobs[i];
				jobs[i] = temp;
			}
		}
	}
}
int main()
{
	struct node edge[15];
	int n, m;
	cout << "enter the number of vertices and edges" << endl;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cout << "enter the source and destination vertex and corresponding weight" << endl;
		cin >> edge[i].vertex1;
		cin >> edge[i].vertex2;
		cin >> edge[i].weight;
	}

	sort(edge, m);
	for (int i = 0; i < n; i++)
	{
		makeset(i);
	}
	int total_cost = 0;
	int count = 0;
	for (int i = 0; i <= n + 1; i++)
	{
		int u = edge[i].vertex1;
		int v = edge[i].vertex2;
		int wt = edge[i].weight;
		if (findparent(u) == findparent(v))
		{
			continue;
		}
		Union(u, v);
		count++;
		total_cost = total_cost + wt;
		cout << u << "-" << v << endl;
		if (count == n - 1)
			break;
	}
	cout << "minimum cost" << total_cost;
}