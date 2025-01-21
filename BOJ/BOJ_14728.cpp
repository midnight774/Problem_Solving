#include <iostream>
#include <vector>
#include <algorithm>

/*
BOJ 14728 벼락치기
풀이 방법 : 배낭 채우기(DP)
 */

using namespace std;

int N, T;
pair<int, int> Score[101] = {};
int DP[101][10001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> T;

	for (int i = 0; i < N; ++i)
	{
		cin >> Score[i].first >> Score[i].second;
	}

	DP[0][Score[0].first] = Score[0].second;

	for (int i = Score[0].first; i <= T; ++i)
	{
		DP[0][i] = Score[0].second;
	}

	int Answer = 0;
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j <= T; ++j)
		{
			DP[i][j] = DP[i - 1][j];

			if (j - Score[i].first >= 0)
				DP[i][j] = max(DP[i][j], DP[i - 1][j - Score[i].first] + Score[i].second);

			Answer = max(Answer, DP[i][j]);
		}

	}

	cout << Answer;
}
