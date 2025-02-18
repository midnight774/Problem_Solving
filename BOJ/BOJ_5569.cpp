#include <iostream>

/*
BOJ 5569 출근 경로
풀이 방법 :DP
 */

using namespace std;

int DP[101][101][2][2] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int W, H;
	cin >> W >> H;

	for (int i = 0; i < H; ++i)
	{
		DP[i][0][1][0] = 1;
	}

	for (int j = 0; j < W; ++j)
	{
		DP[0][j][0][0] = 1;
	}	

	for (int i = 1; i < H; ++i)
	{
		for (int j = 1; j < W; ++j)
		{
			DP[i][j][0][0] += DP[i][j - 1][0][0] + DP[i][j - 1][0][1];
			DP[i][j][0][0] %= 100000;

			DP[i][j][0][1] += DP[i][j - 1][1][0];
			DP[i][j][0][1] %= 100000;

			DP[i][j][1][0] += DP[i - 1][j][1][0] + DP[i - 1][j][1][1];
			DP[i][j][1][0] %= 100000;

			DP[i][j][1][1] += DP[i - 1][j][0][0];
			DP[i][j][1][1] %= 100000;
		}
	}
	
	int Sum = DP[H - 1][W - 1][0][0] + DP[H - 1][W - 1][1][0] + DP[H - 1][W - 1][0][1] + DP[H - 1][W - 1][1][1];
	Sum %= 100000;

	cout << Sum;
}

