#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 2157 여행
풀이 방법 : DP
*/

const int Max = 987654321;
int DP[301][301] = {};
int Score[301][301] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < K; ++i)
	{
		int Src, Dest, CurScore;
		cin >> Src >> Dest >> CurScore;

		if (Src > Dest)
			continue;

		Score[Src][Dest] = max(Score[Src][Dest], CurScore);
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			DP[i][j] = -1;
		}
	}

	DP[1][1] = 0;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (Score[j][i] == 0)
				continue;

			for (int k = 2; k <= i; ++k)
			{
				if (DP[j][k - 1] == -1)
					continue;

				DP[i][k] = max(DP[j][k - 1] + Score[j][i], DP[i][k]);
			}
		}
	}

	int Max = 0;
	for (int i = 1; i <= M; ++i)
		Max = max(Max, DP[N][i]);

	cout << Max;
}

