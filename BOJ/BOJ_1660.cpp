#include <iostream>
#include <vector>

using namespace std;

/*
백준 1660 캡틴 이다솜
풀이 방법 : DP, 누적 합
*/

int TriCnt[121] = {};
int DummyCnt[121] = {};
int DP[300001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		DP[i] = i;
	}

	TriCnt[1] = 1;
	for (int i = 2; i <= 120; ++i)
	{
		TriCnt[i] = TriCnt[i - 1] + i;
	}

	DummyCnt[1] = 1;
	DP[1] = 1;

	for (int i = 2; i <= 120; ++i)
	{
		DummyCnt[i] = TriCnt[i] + DummyCnt[i - 1];
		DP[DummyCnt[i]] = 1;
	}

	if (DP[N] == 1)
	{
		cout << DP[N];
		return 0;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= 120; ++j)
		{
			if (i - DummyCnt[j] < 0)
				break;

			DP[i] = min(DP[i], DP[i - DummyCnt[j]] + DP[DummyCnt[j]]);
		}
	}

	cout << DP[N];
}
