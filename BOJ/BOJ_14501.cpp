#include <iostream>

/*
BOJ 14501 퇴사
풀이 방법 : DP
 */

using namespace std;

int N;
int Answer = 0;
pair<int,int> Price[16] = {};
int DP[16] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Price[i].first >> Price[i].second;
	}

	for (int i = 0; i < N; ++i)
	{
		if (i > 0)
		{
			DP[i] = max(DP[i], DP[i - 1]);
		}

		if (i + Price[i].first - 1 < N)
		{
			int Idx = i + Price[i].first;
			DP[Idx] = max(DP[Idx], DP[i] + Price[i].second);
			Answer = max(DP[Idx], Answer);
		}
	}

	cout << Answer;
}
