#include <iostream>
#include <limits.h>
using namespace std;
struct node
{
	int vertex1;
	int vertex2;
	int weight;
};

int main()
{
	struct node edge[15];
	int n, m;
	cout << "enter the number of vertices and edges" << endl;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, wt;
		cout << "enter the source vertex and destination vertex with weight" << endl;
		cin >> u >> v >> wt;
		edge[i].vertex1 = u;
		edge[i].vertex2 = v;
		edge[i].weight = wt;
	}
	int src;
	cout << "enter the source vertex" << endl;
	cin >> src;
	int dist[n + 1];
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[src] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[edge[j].vertex1] + edge[j].weight < dist[edge[j].vertex2])
				dist[edge[j].vertex2] = dist[edge[j].vertex1] + edge[j].weight;
		}
	}
	int flag = 0;
	for (int j = 0; j < m; j++)
	{
		if (dist[edge[j].vertex1] + edge[j].weight < dist[edge[j].vertex2])
		{
			cout << "negative edge cycle" << endl;
			flag = 1;
		}
	}
	if (flag = 0)
	{

		for (int i = 1; i <= n; i++)
		{
			cout << i << " " << dist[i] << endl;
		}
	}

	return 0;
}
