#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
백준 16197 두 동전
풀이 방법 : BFS
*/

char Board[21][21] = {};
bool Check[21][21][21][21] = {};
int MinMove = 11;
int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,1,-1 };

struct PosInfo
{
	vector<pair<int, int>> vecCoin;
	int MoveCnt = 0;
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;

	PosInfo StartInfo;
	int Cnt = 0;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Board[i][j];

			if (Board[i][j] == 'o')
			{
				StartInfo.vecCoin.push_back(pair<int, int>(i, j));
			}
		}
	}


	queue<PosInfo> qInfo;
	
	{
		int y1, x1, y2, x2;
		y1 = StartInfo.vecCoin[0].first;
		x1 = StartInfo.vecCoin[0].second;
		y2 = StartInfo.vecCoin[1].first;
		x2 = StartInfo.vecCoin[1].second;

		Check[y1][x1][y2][x2] = true;
		Check[y2][x2][y1][x1] = true;
	}

	qInfo.push(StartInfo);

	while (!qInfo.empty())
	{
		PosInfo CurInfo = qInfo.front();
		qInfo.pop();

		bool IsFin = false;

		if (CurInfo.MoveCnt == 10)
			break;

		for (int i = 0; i < 4; ++i)
		{
			PosInfo NextInfo = CurInfo;
			++NextInfo.MoveCnt;
			int OutCnt = 0;

			for (int j = 0; j < 2; ++j)
			{
				NextInfo.vecCoin[j].first += DirY[i];
				NextInfo.vecCoin[j].second += DirX[i];

				int NextY = NextInfo.vecCoin[j].first;
				int NextX = NextInfo.vecCoin[j].second;

				bool IsOut = NextY >= N || NextY < 0
					|| NextX >= M || NextX < 0;

				if (IsOut)
				{
					++OutCnt;
					continue;
				}

				if (Board[NextY][NextX] == '#')
				{
					NextInfo.vecCoin[j].first -= DirY[i];
					NextInfo.vecCoin[j].second -= DirX[i];
				}
			}

			if (OutCnt == 1)
			{
				MinMove = NextInfo.MoveCnt;
				IsFin = true;
				break;
			}

			else if (OutCnt == 2)
				continue;

			int y1, x1, y2, x2;
			y1 = NextInfo.vecCoin[0].first;
			x1 = NextInfo.vecCoin[0].second;
			y2 = NextInfo.vecCoin[1].first;
			x2 = NextInfo.vecCoin[1].second;

			if (Check[y1][x1][y2][x2] || Check[y2][x2][y1][x1])
				continue;

			Check[y1][x1][y2][x2] = true;
			Check[y2][x2][y1][x1] = true;

			qInfo.push(NextInfo);
		}

		if (IsFin)
			break;
	}

	if (MinMove == 11)
		cout << -1;

	else
		cout << MinMove;
}
