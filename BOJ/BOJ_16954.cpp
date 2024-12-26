#include <iostream>
#include <queue>

/*
BOJ 16954 움직이는 미로 탈출
풀이 방법 : BFS
*/

using namespace std;

char Map[8][8] = {};

int DirY[9] = { 1,1,1,-1,-1,-1,0,0,0 };
int DirX[9] = { 1,0,-1,1,0,-1,1,0,-1 };
bool Check[16][8][8] = {};

struct PosInfo
{
	int Y;
	int X;
	int Sec;
};

void NextTurn()
{
	for (int i = 7; i >= 0; --i)
	{
		for (int j = 7; j >= 0; --j)
		{
			if (i == 7)
			{
				Map[i][j] = '.';
			}

			else if (Map[i][j] == '#')
			{
				Map[i][j] = '.';
				Map[i + 1][j] = '#';
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cin >> Map[i][j];
		}
	}
	
	bool Enable = false;

	queue<PosInfo> qPos;

	PosInfo Start;
	Start.Y = 7;
	Start.X = 0;
	Start.Sec = 0;
	qPos.push(Start);

	Check[0][7][0] = true;
	int Time = 0;
	while (!qPos.empty())
	{
		PosInfo Cur = qPos.front();
		qPos.pop();

		if (Cur.Sec != Time)
		{
			++Time;
			NextTurn();
		}
		
		if (Cur.Y == 0 && Cur.X == 7)
		{
			Enable = true;
			break;
		}

		if (Map[Cur.Y][Cur.X] == '#')
			continue;

		for (int i = 0; i < 9; ++i)
		{
			int NextY = Cur.Y + DirY[i];
			int NextX = Cur.X + DirX[i];

			if (NextY < 0 || NextY >= 8 || NextX < 0 || NextX >= 8)
				continue;

			if (Check[Cur.Sec + 1][NextY][NextX])
				continue;

			Check[Cur.Sec + 1][NextY][NextX] = true;
			if (Map[NextY][NextX] == '#')
				continue;

			PosInfo Next;
			Next.Y = NextY;
			Next.X = NextX;
			Next.Sec = Cur.Sec + 1;

			qPos.push(Next);
		}
	}
	
	if (Enable)
		cout << 1;

	else
		cout << 0;
}
