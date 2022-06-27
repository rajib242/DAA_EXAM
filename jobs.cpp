#include <iostream>
using namespace std;

struct node
{
	char id;
	int deadline;
	int profit;
};
int min(int num1, int num2)
{
	if (num1 > num2)
		return num2;
	else
		return num1;
}
void sort(struct node jobs[], int n)
{
	struct node temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (jobs[i].profit < jobs[j].profit)
			{
				temp = jobs[j];
				jobs[j] = jobs[i];
				jobs[i] = temp;
			}
		}
	}
}
void JSD(struct node jobs[], int n)
{
	sort(jobs, n);
	bool slot[n];
	int solution[n];
	int cost = 0;
	for (int i = 0; i < n; i++)
	{
		slot[i] = false;
		// solution[i]=0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
		{
			if (slot[j] == false)
			{
				slot[j] = true;
				solution[j] = i;
				cost += jobs[i].profit;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << jobs[solution[i]].id << endl;
	cout << cost;
}

int main()
{
	int n;
	cout << "how many jobs you want to do" << endl;
	cin >> n;
	struct node jobs[n];
	for (int i = 0; i < n; i++)
	{
		cout << "enter the id,deadline and profit" << endl;
		cin >> jobs[i].id;
		cin >> jobs[i].deadline;
		cin >> jobs[i].profit;
	}
	JSD(jobs, n);

	return 0;
}