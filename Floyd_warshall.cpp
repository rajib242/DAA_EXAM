#include <iostream>
#include <limits.h>
using namespace std;
#define v 4
void apsp(int p[v][v], int s, int t)
{
	if (s == t)
		cout << s;
	else if ((p[s][t]) == -1)
		cout << "no path exists";
	else
	{

		apsp(p, s, (p[s][t]));
		cout << "->";
		cout << t;
	}
}

void floyd_warshall(int graph[v][v], int s, int t)
{
	int dist[v][v];
	int p[v][v];
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			dist[i][j] = graph[i][j];
			if (i == j || graph[i][j] == INT_MAX)
				p[i][j] = -1;
			else
				p[i][j] = i;
		}
	}

	for (int k = 0; k < v; k++)
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if ((dist[i][k] + dist[k][j]) < dist[i][j] && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					p[i][j] = k;
				}
			}
		}
	}
	cout << "cost matrix" << endl;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (dist[i][j] == INT_MAX)
				cout << "inf";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	apsp(p, s, t);
	if (dist[s][t] == INT_MAX)
		cout << "  no cost";
	else
		cout << "  cost=" << dist[s][t];
}

int main()
{

	int graph[v][v] = {{0, INT_MAX, -2, INT_MAX},
					   {4, 0, 3, INT_MAX},
					   {INT_MAX, INT_MAX, 0, 2},
					   {INT_MAX, -1, INT_MAX, 0}};

	int a, b;
	cout << "enter the two node which you want distance" << endl;
	cin >> a >> b;
	floyd_warshall(graph, a, b);

	return 0;
}
