#include <iostream>
using namespace std;

int arr[8][8] =
{
	0, 1, 1, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 0, 1, 0,
	0, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

char cc[9] = "ABCDEFGH";

int main()
{
	char ch;
	cin >> ch;
	int yIdx = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] + 'A' == ch)
			{
				yIdx = i;
				break;
			}
		}
	}
	for (int j = 0; j < 8; j++)
	{
		if (arr[yIdx][j] == 0) continue;
		cout << cc[j] << " ";
	}
}