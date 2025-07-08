#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 14499 주사위 굴리기
풀이 방법 : 구현
*/

//위, 아래, 동, 서, 남, 북
int Plain[6] = { 0,0,0,0,0,0 };
int DirY[5] = { 0,0,0,-1,1 };
int DirX[5] = { 0,1,-1,0,0 };
int Board[21][21] = {};

void Move(int Dir)
{
	switch (Dir)
	{
	case 1:
	{
		int Temp = Plain[0];
		Plain[0] = Plain[3];
		Plain[3] = Plain[1];
		Plain[1] = Plain[2];
		Plain[2] = Temp;
	}
		break;
	case 2:
	{
		int Temp = Plain[0];
		Plain[0] = Plain[2];
		Plain[2] = Plain[1];
		Plain[1] = Plain[3];
		Plain[3] = Temp;
	}
		break;
	case 3:
	{
		int Temp = Plain[0];
		Plain[0] = Plain[4];
		Plain[4] = Plain[1];
		Plain[1] = Plain[5];
		Plain[5] = Temp;
	}
		break;
	case 4:
	{
		int Temp = Plain[0];
		Plain[0] = Plain[5];
		Plain[5] = Plain[1];
		Plain[1] = Plain[4];
		Plain[4] = Temp;
	}
		break;
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	
	int N, M, y, x, K;
	cin >> N >> M >> y >> x >> K;

	vector<int> vecCmd(K);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Board[i][j];
		}
	}

	for (int i = 0; i < K; ++i)
	{
		cin >> vecCmd[i];
	}

	for (int i = 0; i < K; ++i)
	{
		int Dir = vecCmd[i];
		int NextY = y + DirY[Dir];
		int NextX = x + DirX[Dir];

		if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= M)
			continue;

		y = NextY;
		x = NextX;
		
		Move(Dir);

		if (Board[y][x] == 0)
			Board[y][x] = Plain[1];

		else
		{
			Plain[1] = Board[y][x];
			Board[y][x] = 0;
		}

		cout << Plain[0] << '\n';
		
	}


}

