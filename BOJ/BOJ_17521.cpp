#include <iostream>

using namespace std;

/*
BOJ 17521 Byte Coin
풀이 방법 : 브루트 포스, 재귀
*/

int N, W;
long long Max = 0;
long long Price[15] = {};

void Solve(int CurDate, long long CurMoney, long long CurCoinCnt)
{
	if (CurDate == N - 1)
	{
		Max = max(CurMoney + CurCoinCnt * Price[CurDate], Max);
		return;
	}

	if (CurMoney >= Price[CurDate])
	{
		long long Cnt = CurMoney / Price[CurDate];
		Solve(CurDate + 1, CurMoney % Price[CurDate], CurCoinCnt + Cnt);
	}

	if (CurCoinCnt > 0)
	{
		Solve(CurDate + 1, CurMoney + CurCoinCnt * Price[CurDate], 0);
	}

	Solve(CurDate + 1, CurMoney, CurCoinCnt);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> W;

	for (int i = 0; i < N; ++i)
	{
		cin >> Price[i];
	}

	Solve(0, W, 0);

	cout << Max;
}

