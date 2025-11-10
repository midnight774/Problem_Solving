#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 1633 최고의 팀 만들기
풀이 방법 : DP
*/

int DP[1001][16][16] = {};
int Score[1001][2];

int GetMax(int Depth, int WCnt, int BCnt)
{
	if (DP[Depth][WCnt][BCnt] != -1)
		return DP[Depth][WCnt][BCnt];

	int CurMax = 0;
	if(Depth + 1 > WCnt + BCnt)
		CurMax = GetMax(Depth - 1, WCnt, BCnt);

	if(WCnt > 0)
		CurMax = max(GetMax(Depth - 1, WCnt - 1, BCnt) + Score[Depth][0], CurMax);

	if(BCnt > 0)
	{
		CurMax = max(GetMax(Depth - 1, WCnt, BCnt - 1) + Score[Depth][1], CurMax);
	}

	DP[Depth][WCnt][BCnt] = CurMax;
	return CurMax;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int Cnt = 0;

	while (!cin.eof())
	{
		++Cnt;
		int W, B;
		cin >> W >> B;
		Score[Cnt][0] = W;
		Score[Cnt][1] = B;
	}

	for (int i = 0; i < Cnt; ++i)
	{
		for (int j = 0; j <= 15; ++j)
		{
			for (int k = 0; k <= 15; ++k)
			{
				DP[i][j][k] = -1;
			}
		}
	}

	DP[1][1][0] = Score[1][0];
	DP[1][0][1] = Score[1][1];
	DP[1][0][0] = 0;

	cout << GetMax(Cnt - 1, 15, 15);
	
}


