#include<iostream>
#include<cstring>
using namespace std;
int T, n, m;
bool areFriends[10][10];
bool check[10];

int countPairings()
{
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1)
		return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!check[pairWith] && areFriends[firstFree][pairWith])
		{
			check[pairWith] = check[firstFree] = true;
			ret += countPairings();
			check[pairWith] = check[firstFree] = false;
		}
	}
	return ret;
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(areFriends, false, sizeof(areFriends));
		memset(check, false, sizeof(check));
		cin >> n >> m;
		for (int j = 0; j < m; j++)
		{
			int num1, num2;
			cin >> num1 >> num2;
			areFriends[num1][num2] = true;
			areFriends[num2][num1] = true;
		}
		cout << countPairings() << "\n";
	}
}