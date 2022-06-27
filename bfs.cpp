#include <iostream>
using namespace std;
#define max 7
int queue[max];
int front = -1, rear = -1;

int isEmpty()
{
	if (front == -1 || front == -1)
		return 1;
	else
		return 0;
}

void enqueue(int x)
{

	if (rear == max - 1)
		cout << "queue is overflow";
	else if (front == -1 && rear == -1)
	{
		front =rear=0;
		queue[rear] = x;
	}
	else
	{
		rear++;
		queue[rear] = x;
	}
}
int dequeue()
{
	int y;
	if (front == -1 || front > rear)
		cout << "queue is underflow";

	else if (front == rear)
	{

		y = queue[front];
		front = rear =-1;
	}
	else
	{

		y = queue[front];
		front++;
	}

	return y;
}
int main()
{

	int node;
	int i;
	cout << "enter the source node ";
	cin >> i;
	int visited[4] = {0, 0, 0, 0};
	int a[7][7] = {
		{0, 1, 1,0},
		{1, 0, 1, 1},
		{1, 1, 0, 1},
		{0,1,1,0}};
	cout << i << endl;
	visited[i] = 1;
	enqueue(i); // Enqueue i for exploration
	while (!isEmpty())
	{
		int node = dequeue();
		for (int j = 0; j <4 ; j++)
		{
			if (a[node][j] == 1 && visited[j] == 0)
			{
				cout << j << endl;
				visited[j] = 1;
				enqueue(j);
			}
		}
	}
	return 0;
}
