#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 9207 페그 솔리테어
풀이 방법 : 백트래킹
*/

string Board[9] = {};
int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,1,-1 };
int MinCnt = 8;
int MinMove = 10;

void DFS(int MoveCnt)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (Board[i][j] != 'o')
				continue;

			for (int k = 0; k < 4; ++k)
			{
				int NextY = i + DirY[k];
				int NextX = j + DirX[k];

				int JumpY = i + DirY[k] * 2;
				int JumpX = j + DirX[k] * 2;

				bool IsOut = NextY >= 5 || NextY < 0 || NextX >= 9 || NextX < 0 ||
					JumpY >= 5 || JumpY < 0 || JumpX >= 9 || JumpX < 0;

				if (IsOut)
					continue;

				if (Board[NextY][NextX] == 'o'
					&& Board[JumpY][JumpX] == '.')
				{
					Board[i][j] = '.';
					Board[NextY][NextX] = '.';
					Board[JumpY][JumpX] = 'o';

					DFS(MoveCnt + 1);

					Board[i][j] = 'o';
					Board[NextY][NextX] = 'o';
					Board[JumpY][JumpX] = '.';
				}
			}
		}
	}

	int Cnt = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (Board[i][j] == 'o')
				++Cnt;
		}
	}

	if (MinCnt > Cnt)
	{
		MinCnt = Cnt;
		MinMove = MoveCnt;
	}

	else if (MinCnt == Cnt)
	{
		MinMove = min(MinMove, MoveCnt);
	}
}



int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	while (N > 0)
	{
		--N;
		MinCnt = 8;
		MinMove = 10;
		
		for (int i = 0; i < 5; ++i)
		{
			cin >> Board[i];
		}

		DFS(0);
		cout << MinCnt << ' ' << MinMove << '\n';
	}
	
}

