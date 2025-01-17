#include <iostream>

/*
BOJ 13567 로봇
풀이 방법 : 구현
 */

using namespace std;

int DirY[4] = { 0,-1,0,1 };
int DirX[4] = { 1,0,-1,0 };

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;

	int CurDir = 0;

	int PosY = 0;
	int PosX = 0;

	bool Enable = true;
	for (int i = 0; i < N; ++i)
	{
		string Cmd;
		int d;

		cin >> Cmd >> d;

		if (!Enable)
			continue;

		if (Cmd == "MOVE")
		{
			PosY += DirY[CurDir] * d;
			PosX += DirX[CurDir] * d;

			if (PosY > M || PosY< 0 || PosX > M || PosX < 0)
			{
				Enable = false;
			}
		}

		else
		{
			if (d == 1)
			{
				++CurDir;
				if (CurDir == 4)
					CurDir = 0;
			}

			else
			{
				--CurDir;
				if (CurDir == -1)
					CurDir = 3;
			}
		}
	}

	if (Enable)
	{
		cout << PosX << ' ' << PosY;
	}

	else
		cout << -1;
}
