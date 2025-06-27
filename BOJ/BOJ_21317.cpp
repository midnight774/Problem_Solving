
#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 21317번 징검다리 건너기
풀이 방법 : DP
*/

int Power[21][2] = {};
int DP[21][2] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i < N; ++i)
	{
		cin >> Power[i][0] >> Power[i][1];
	}

	for (int i = 1; i <= N; ++i)
	{
		DP[i][0] = 987654321;
		DP[i][1] = 987654321;
	}

	int K;
	cin >> K;

	DP[1][0] = 0;
	DP[2][0] = Power[1][0];

	for (int i = 3; i <= N; ++i)
	{
		DP[i][0] = min(DP[i - 1][0] + Power[i - 1][0], DP[i - 2][0] + Power[i - 2][1]);
		
		if (i > 3)
		{
			DP[i][1] = min(DP[i][1], DP[i - 3][0] + K);
			DP[i][1] = min(DP[i][1], min(DP[i - 1][1] + Power[i - 1][0] , DP[i - 2][1] + Power[i - 2][1]));
		}
	}
	
	cout << min(DP[N][0], DP[N][1]);
}

