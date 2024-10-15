#include <iostream>
#include <vector>
using namespace std;

int DP[10001] = {};

/*
백준 2624번 동전 바꿔주기
풀이 방법 : DP
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T, K;
	cin >> T >> K;
	vector<pair<int, int>> vecCoin(K);

	for (int i = 0; i < K; ++i)
	{
		cin >> vecCoin[i].first >> vecCoin[i].second;
	}

	DP[0] = 1;

	for (int i = 0; i < K; ++i)
	{
		for (int j = T; j >= 1; --j)
		{
			int Sum = 0;

			for (int k = 0; k < vecCoin[i].second; ++k)
			{
				Sum += vecCoin[i].first;

				if (Sum <= T && j - Sum >= 0)
				{
					DP[j] += DP[j - Sum];
				}
			}
		}
	}

	cout<<DP[T];
}
