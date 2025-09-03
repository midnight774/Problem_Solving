#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 9047 6174
풀이 방법 : DP
*/

int DP[10000] = {};

int GetCnt(int Num)
{
	if (DP[Num] != -1)
		return DP[Num];

	vector<int> vecNum(4);
	int CurNum = Num;
	for (int i = 0; i < 4; ++i)
	{
		vecNum[i] = CurNum % 10;
		CurNum /= 10;
	}

	sort(vecNum.begin(), vecNum.end());
	int Max = vecNum[3] * 1000 + vecNum[2] * 100 + vecNum[1] * 10 + vecNum[0];
	int Min = vecNum[0] * 1000 + vecNum[1] * 100 + vecNum[2] * 10 + vecNum[3];

	DP[Num] = GetCnt(Max - Min) + 1;
	return DP[Num];

}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i <= 9999; ++i)
		DP[i] = -1;

	DP[6174] = 0;

	while (T > 0)
	{
		--T;
		int Num;
		cin >> Num;

		cout << GetCnt(Num) << '\n';
	}
}

