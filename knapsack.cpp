#include <iostream>
using namespace std;

struct node
{
	float profit;
	float weight;
	float ratio;
};
void sort(struct node temp[], int n)
{
	struct node count;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (temp[i].ratio < temp[j].ratio)
			{
				count = temp[j];
				temp[j] = temp[i];
				temp[i] = count;
			}
		}
	}
}
void knapsack(struct node arr[], int n, int m)
{
	float x[n];
	float tp = 0.0;
	int j;
	for (int i = 0; i < n; i++)
	{
		x[i] = 0.0;
	}
	int u = m;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].weight > u)
		{
			j = i;
			break;
		}
		x[i] = 1.0;
		tp = tp + arr[i].profit;
		u = u - arr[i].weight;
	}

	if (j <= n)
	{

		x[j] = u / arr[j].weight;
	}
	tp = tp + (x[j] * arr[j].profit);

	cout << "Maximum profit" << tp << endl;
	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
}

int main()
{
	int n, m;
	cout << "enter the number of objects " << endl;
	cin >> n;
	struct node arr[n];
	for (int i = 0; i < n; i++)
	{
		cout << "enter the profit and weight" << endl;
		cin >> arr[i].profit;
		cin >> arr[i].weight;
	}

	cout << "Enter the capacity" << endl;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		arr[i].ratio = arr[i].profit / arr[i].weight;
	}
	sort(arr, n);
	knapsack(arr, n, m);
}