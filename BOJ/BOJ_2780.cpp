#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 2780 비밀번호
풀이 방법 : DP
*/

int NumIdx[10][4] =
{
	{7,-1,-1,-1},
	{2, 4,-1,-1},
	{1,3,5,-1},
	{2,6,-1,-1},
	{1,5,7,-1},
	{2,4,6,8},
	{3,5,9,-1},
	{0,4,8,-1},
	{5,7,9,-1},
	{6,8,-1,-1}
};

int N;
int Answer = 0;
int DP[1001][10] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < 10; ++i)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i < 1001; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				int Idx = NumIdx[j][k];
				if (Idx == -1)
					break;

				DP[i][Idx] += DP[i - 1][j];
				DP[i][Idx] %= 1234567;
			}
		}
	}

	while (T>0)
	{
		--T;
		cin >> N;

		int Answer = 0;

		for (int i = 0; i < 10; ++i)
		{
			Answer += DP[N][i];
			Answer %= 1234567;
		}

		cout << Answer<<'\n';

	}

}

