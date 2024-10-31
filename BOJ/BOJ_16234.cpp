#include <iostream>
#include <set>

/*
BOJ 16234 인구 이동
풀이 방법 : DFS
*/

using namespace std;

int Cnt[51][51] = {};
bool Check[51][51] = {};
int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,1,-1 };
int Day = 0;
int N, L, R;


void DFS(int CurY, int CurX, int& UnionCnt, int& HumanCnt, set<pair<int,int>>& set)
{
	for (int i = 0; i < 4; ++i)
	{
		int NextY = CurY + DirY[i];
		int NextX = CurX + DirX[i];

		if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= N)
			continue;

		if (Check[NextY][NextX])
			continue;

		int Minus = abs(Cnt[CurY][CurX] - Cnt[NextY][NextX]);

		if (L <= Minus && Minus <= R)
		{
			++UnionCnt;
			HumanCnt += Cnt[NextY][NextX];

			Check[NextY][NextX] = true;
			set.insert(pair<int, int>(NextY, NextX));
			DFS(NextY, NextX, UnionCnt, HumanCnt, set);
		}
	}

	Cnt[CurY][CurX] = HumanCnt / UnionCnt;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> Cnt[i][j];


	while (true)
	{
		bool Enable = false;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (Check[i][j])
					continue;

				Check[i][j] = true;
				int UCnt = 1;
				int Human = Cnt[i][j];
				set<pair<int, int>> setPair;
				setPair.insert(pair<int, int>(i, j));
				DFS(i, j, UCnt, Human, setPair);

				if (UCnt > 1)
				{
					auto iter = setPair.begin();
					auto iterEnd = setPair.end();

					for (; iter != iterEnd; ++iter)
						Cnt[iter->first][iter->second] = Human / UCnt;
					Enable = true;
				}
			}
		}

		if (!Enable)
			break;

		++Day;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				Check[i][j] = false;
	}

	cout << Day;

}

