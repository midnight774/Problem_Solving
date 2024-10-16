#include <iostream>
#include <vector>

using namespace std;


/*
백준 2225번 합 분해
풀이 방법 : DP

N을 K개로 만드는 것 == N-(i) 를 K - 1개로 만드는 경우의 수 들의 합
*/

long long DP[201][201] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; ++i)
	{
		DP[i][1] = 1;
	}

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			for (int k = 0; k <= i; ++k)
			{
				DP[i][j] += DP[i - k][j - 1] % 1000000000;
				DP[i][j] %= 1000000000;
			}
		}
	}

	cout << DP[N][K];
}
