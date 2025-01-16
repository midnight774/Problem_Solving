#include <iostream>

/*
BOJ 2186 문자판
풀이 방법 : DFS + DP
 */

using namespace std;

int N, M, K;
char Board[101][101] = {};
int DP[101][101][81] = {};
int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,-1,1 };
int Answer = 0;
string Target;

void DFS(int Depth, int MaxLength)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Target[Depth] == Board[i][j])
			{
				for (int d = 0; d < 4; ++d)
				{
					for (int l = 1; l <= K; ++l)
					{
						int Y = i + DirY[d] * l;
						int X = j + DirX[d] * l;

						if (Y >= N || Y < 0 || X >= M || X < 0)
							break;

						if (Board[Y][X] == Target[Depth - 1])
						{
							if(Depth == MaxLength -1)
								Answer += DP[Y][X][Depth - 1];

							DP[i][j][Depth] += DP[Y][X][Depth - 1];
						}
					}
				}
			}
		}
	}

	if(Depth + 1 != MaxLength)
		DFS(Depth + 1, MaxLength);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> Board[i];
	}

	cin >> Target;

	int Length = Target.length();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Board[i][j] == Target[0])
				DP[i][j][0] = 1;
		}
	}

	DFS(1, Length);

	
	cout << Answer;

}
