#include <iostream>
#include <vector>

/*
BOJ 17281 ⚾
풀이 방법 : 브루트 포스
*/

using namespace std;

int N;
int HitInfo[51][9];
bool Check[9] = {};
int ScoreMax = 0;

void DFS(int Depth, vector<int> vecIdx)
{
	if (Depth == 3)
	{
		vecIdx.push_back(0);
		DFS(Depth + 1, vecIdx);
		return;
	}

	if (vecIdx.size() == 9)
	{
		int CurScore = 0;
		int CurIdx = 0;
		int CurInning = 0;
		int CurOut = 0;
		bool IsStanding[3] = {};

		while (CurInning < N)
		{
			int CurHit = HitInfo[CurInning][vecIdx[CurIdx]];
			++CurIdx;

			if (CurIdx == 9)
				CurIdx = 0;

			if (CurHit == 0)
			{
				if (CurOut == 2)
				{
					++CurInning;
					CurOut = 0;

					for (int i = 0; i < 3; ++i)
					{
						IsStanding[i] = false;
					}
				}

				else
					++CurOut;

				continue;
			}

			else if (CurHit == 4)
			{
				int Score = 1;

				for (int i = 0; i < 3; ++i)
				{
					if (IsStanding[i])
					{
						IsStanding[i] = false;
						++Score;
					}
				}

				CurScore += Score;
			}

			else
			{
				int Score = 0;
				for (int i = 2; i >= 0; --i)
				{
					if (IsStanding[i])
					{
						IsStanding[i] = false;

						if (i + CurHit >= 3)
							++Score;

						else
						{
							IsStanding[i + CurHit] = true;
						}
					}
				}

				CurScore += Score;
				IsStanding[CurHit - 1] = true;
			}
		}

		ScoreMax = max(CurScore, ScoreMax);
		return;
	}

	for (int i = 1; i < 9; ++i)
	{
		if (!Check[i])
		{
			vector<int> vecNext = vecIdx;
			Check[i] = true;
			vecNext.push_back(i);
			DFS(Depth + 1, vecNext);
			Check[i] = false;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cin >> HitInfo[i][j];
	}

	DFS(0, vector<int>());

	cout << ScoreMax;
}
