#include<iostream>
using namespace std;
int dfs(int g[6][6], int visited[6], int i)
{
	cout << i << endl;
	for (int j = 0; j < 6; j++)
	{
		if (g[i][j] == 1 && visited[j]== false)
		{
			visited[j] = 1;
			dfs(g,visited,j);
		}
	}
}
int main()
{
	int i;
	cout << "Enter the source vertex" << endl;
	cin >> i;
	int g[6][6] = {{0, 1, 1, 0, 0, 0},
				   {1, 0, 0, 1, 1, 0},
				   {1, 0, 0, 0, 1, 0},
				   {0, 1, 0, 0, 1, 1},
				   {0, 1, 1, 1, 0, 1},
				   {0, 0, 0, 1, 1, 0}};
	int visited[6] = {0, 0, 0, 0, 0, 0};
	visited[i] = 1;
	dfs(g, visited, i);
}