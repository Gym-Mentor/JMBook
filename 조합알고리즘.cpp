#include<iostream>
#include<vector>
using namespace std;
vector<int> picked;
void printPicked()
{
	for (int i = 0; i < picked.size(); i++)
	{
		cout << picked[i] << " ";
	}
	cout << "\n";
}
void pick(int n, int topick)
{
	if (topick == 0) { printPicked(); return; }
	int smallpicked = picked.empty() ? 0 : picked.back() + 1;
	for (int i = smallpicked; i < n; i++)
	{
		picked.push_back(i);
		pick(n, topick - 1);
		picked.pop_back();
	}
}
int main()
{
	int n, topick;
	cout << "n���� �� �߿��� m���� ���� ���� �Է��ϼ���";
	cin >> n >> topick;
	pick(n, topick);
}