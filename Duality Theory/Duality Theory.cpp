#include<iostream>
#include<string>
using namespace std;
int main()
{
	int c, v;
	cout << "Total Variables :";
	cin >> v;
	cout << "Total Constraints :";
	cin >> c;
	int **arr;
	arr = new int *[c + 1];
	for (int i = 0; i < (c + 1); i++)
	{
		arr[i] = new int[v + 1];
	}
	int **new_arr;
	new_arr = new int *[v + 1];
	for (int i = 0; i < (v + 1); i++)
	{
		new_arr[i] = new int[c + 1];
	}
	cout << "\n";
	cout << "MAX Z= ";
	for (int i = 0; i < (v); i++)
	{
		cin >> arr[c][i];
	}
	cout << "S.T ";
	for (int i = 0; i < (c); i++)
	{
		for (int j = 0; j < (v + 1); j++)
		{
			cin >> arr[i][j];
		}
	}
	arr[c][v] = 0;
	cout << "\n";
	cout << "A = ";
	for (int i = 0; i < (c + 1); i++)
	{
		for (int j = 0; j < (v + 1); j++)
		{
			cout << "\t";
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n";
	cout << "At = ";
	for (int i = 0; i < (c + 1); i++)
	{
		for (int j = 0; j < (v + 1); j++)
		{
			new_arr[j][i] = arr[i][j];
		}
	}
	for (int i = 0; i < (v + 1); i++)
	{
		for (int j = 0; j < (c + 1); j++)
		{
			cout << "\t";
			cout << new_arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 1; i++) // diplay min
	{
		int k = 0;
		cout << "Min W = ";
		for (int j = 0; j < (c); j++)
		{
			cout << "(" << new_arr[v][j] << ")" << "y" << ++k;
			if (k < c)
				cout << " + ";
		}
		cout << endl;
	}
	cout << "S.T\n";
	for (int i = 0; i < (v); i++) // display subject to
	{
		int k = 0;
		cout << "\t ";
		for (int j = 0; j < (c + 1); j++)
		{
			cout << "(" << new_arr[i][j] << ")";
			if (k < (c - 1))
				cout << "y" << ++k << " + ";
			else if (j < c)
				cout << " >= ";
		}
		cout << endl;
	}
	cout << "\t ";
	for (int i = 1; i < (c + 1); i++)
	{
		cout << "y" << i;
		if (i < c)
			cout << ",";
	}
	cout << " >= 0\n";
	delete[] arr;
	delete[] new_arr;}