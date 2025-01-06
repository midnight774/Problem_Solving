#include <iostream>

/*
BOJ 1344 축구
풀이 방법 : DP
 */

using namespace std;

double DP[20][20][20] = {};
bool IsNonPrime[20] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	IsNonPrime[0] = true;
	IsNonPrime[1] = true;

	for (int i = 2; i <= 20; ++i)
	{
		if (IsNonPrime[i])
			continue;

		int Num = i + i;

		while (Num <= 20)
		{
			IsNonPrime[Num] = true;
			Num += i;
		}
	}

	DP[0][0][0] = 1.0;
	
	for (int i = 1; i <= 18; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			for (int k = 0; k <= i; ++k)
			{
				DP[i][j][k] += DP[i - 1][j][k] * ((100 - N) / 100.0 * (100 - M) / 100.0);

				if (j > 0)
				{
					DP[i][j][k] += DP[i - 1][j - 1][k] * ((N) / 100.0 * (100 - M) / 100.0);
				}

				if (k > 0)
				{
					DP[i][j][k] += DP[i - 1][j][k - 1] * ((100 - N) / 100.0 * (M) / 100.0);
				}

				if (j > 0 && k > 0)
				{
					DP[i][j][k] += DP[i - 1][j - 1][k - 1] * ((N) / 100.0 * (M) / 100.0);
				}
			}
		}

	}

	double Answer = 0.0;

	for (int i = 0; i <= 18; ++i)
	{
		for (int j = 0; j <= 18; ++j)
		{
			if (IsNonPrime[i] && IsNonPrime[j])
				continue;

			Answer += DP[18][i][j];
		}
	}

	cout << fixed;
	cout.precision(6);
	cout << Answer;
}
