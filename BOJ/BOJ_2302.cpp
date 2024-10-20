#include <iostream>

/*
백준 2302 극장 좌석
풀이 방법 : DP
*/

using namespace std;

int N, M;
int  DP[41][3] = {};
bool IsVIP[41] = {};
int Answer = 0;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int Num;
		cin >> Num;
		IsVIP[Num] = true;
	}

	if (N == 1)
	{
		cout << 1;
		return 0;
	}

	DP[1][1] = 1;
	
	if(!IsVIP[1])
		DP[1][2] = 1;

	for (int i = 2; i <= N; ++i)
	{
		DP[i][1] = DP[i - 1][0] + DP[i - 1][1];

		if(!IsVIP[i])
		{
			DP[i][2] = DP[i - 1][0] + DP[i - 1][1];
			DP[i][0] = DP[i - 1][2];
		}
	}

	cout << DP[N][0] + DP[N][1];
}
