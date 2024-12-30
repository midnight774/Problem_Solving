#include <iostream>

/*
BOJ 17404 RGB거리 2
풀이 방법 : DP
*/

using namespace std;

int Cost[1001][3] = {};
int DP[1001][3] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> Cost[i][j];
		}
	}

	int Min = 987654321;

	for (int i = 0; i < 3; ++i)
	{
		DP[0][0] = 987654321;
		DP[0][1] = 987654321;
		DP[0][2] = 987654321;

		DP[0][i] = Cost[0][i];

		for (int j = 1; j < N; ++j)
		{
			DP[j][0] = min(DP[j - 1][1], DP[j - 1][2]) + Cost[j][0];
			DP[j][1] = min(DP[j - 1][0], DP[j - 1][2]) + Cost[j][1];
			DP[j][2] = min(DP[j - 1][0], DP[j - 1][1]) + Cost[j][2];
		}

		for (int j = 0; j < 3; ++j)
		{
			if (i == j)
				continue;
			
			Min = min(Min, DP[N - 1][j]);
		}
	}

	cout << Min;
	
}
