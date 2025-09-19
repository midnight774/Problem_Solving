#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 12026 BOJ 거리
풀이 방법 : DP
*/

string Road = {};
int DP[1001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cin >> Road;

	for (int i = 0; i < N; ++i)
		DP[i] = 987654321;

	DP[0] = 0;

	for (int i = 1; i < N; ++i)
	{
		char PrevTarget = ' ';

		switch (Road[i])
		{
		case 'B':
			PrevTarget = 'J';
			break;
		case 'O':
			PrevTarget = 'B';
			break;
		case 'J':
			PrevTarget = 'O';
			break;
		}

		for (int j = 0; j < i; ++j)
		{
			if (Road[j] == PrevTarget)
			{
				DP[i] = min(DP[j] + (i - j) * (i - j), DP[i]);
			}
		}
	}

	if (DP[N - 1] == 987654321)
		DP[N - 1] = -1;

	cout << DP[N - 1];
}

