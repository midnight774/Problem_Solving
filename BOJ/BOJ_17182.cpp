#include <iostream>

using namespace std;

/*
BOJ 17182번 우주 탐사선
풀이 방법 : 백트래킹 + 플로이드
*/

int N, K;
int Dist[11][11] = {};
bool Check[11] = {};
int Ans = 10000;

void BT(int CurPos, int CurTime, int Cnt)
{
	if (Cnt == N)
	{
		Ans = min(CurTime, Ans);
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (Check[i])
			continue;

		Check[i] = true;
		BT(i, CurTime + Dist[CurPos][i], Cnt + 1);
		Check[i] = false;

	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Dist[i][j];
		}
	}

	Check[K] = true;

	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				Dist[i][j] = min(Dist[i][k] + Dist[k][j], Dist[i][j]);
			}
		}
	}

	BT(K, 0, 1);

	cout << Ans;
}

