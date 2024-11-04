#include <iostream>
#include <vector>

/*
BOJ 1937 욕심쟁이 판다
풀이 방법 : DP
*/

using namespace std;

int N;
bool Check[501][501] = {};
int DP[501][501] = {};
int Amount[501][501] = {};
int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,1,-1 };
int MaxCnt = 1;

void Recursive(int CurY, int CurX)
{
	int CurAmount = Amount[CurY][CurX];

	for (int i = 0; i < 4; ++i)
	{
		int NextY = CurY + DirY[i];
		int NextX = CurX + DirX[i];

		bool IsOut = NextY >= N || NextY < 0 || NextX >= N || NextX < 0;

		if (IsOut)
			continue;

		if (CurAmount <= Amount[NextY][NextX])
			continue;

		if (Check[NextY][NextX])
		{
			DP[CurY][CurX] = max(DP[CurY][CurX], DP[NextY][NextX] + 1);
			MaxCnt = max(MaxCnt, DP[CurY][CurX]);
			continue;
		}

		Check[NextY][NextX] = true;
		Recursive(NextY, NextX);
		DP[CurY][CurX] = max(DP[CurY][CurX], DP[NextY][NextX] + 1);

	}

	MaxCnt = max(MaxCnt, DP[CurY][CurX]);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	vector<pair<int, int>> vecPair;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Amount[i][j];
			DP[i][j] = 1;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Check[i][j])
				continue;

			Recursive(i, j);
		}
	}

	cout << MaxCnt;

}
