#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 7562 나이트의 이동
풀이 방법 : BFS
*/

bool Check[301][301] = {};
int DirY[8] = {2,1,2,1,-2,-1,-2,-1};
int DirX[8] = {1,2,-1,-2,1,2,-1,-2};

struct Info
{
	int Y;
	int X;
	int Cnt;
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T > 0)
	{
		--T;

		int L;
		cin >> L;

		for (int i = 0; i < L; ++i)
			for (int j = 0; j < L; ++j)
				Check[i][j] = false;

		int sY, sX, dY, dX;
		cin >> sY >> sX >> dY >> dX;

		if (sY == dY && sX == dX)
		{
			cout << 0 << '\n';
			continue;
		}

		queue<Info> qInfo;
		Info Start;
		Start.Y = sY;
		Start.X = sX;
		Start.Cnt = 0;


		Check[sY][sX] = true;
		qInfo.push(Start);

		bool Enable = false;
		while (!qInfo.empty())
		{
			Info CurInfo = qInfo.front();
			qInfo.pop();

			for (int i = 0; i < 8; ++i)
			{
				int NextY = CurInfo.Y + DirY[i];
				int NextX = CurInfo.X + DirX[i];

				bool IsOut = NextY < 0 || NextY >= L || NextX < 0 || NextX >= L;
				if (IsOut)
					continue;

				if (Check[NextY][NextX])
					continue;

				Check[NextY][NextX] = true;

				if (NextY == dY && NextX == dX)
				{
					cout << CurInfo.Cnt + 1 << '\n';
					Enable = true;
					break;
				}

				Info NextInfo;
				NextInfo.Y = NextY;
				NextInfo.X = NextX;
				NextInfo.Cnt = CurInfo.Cnt + 1;

				qInfo.push(NextInfo);
			}

			if (Enable)
				break;
		}
		

	}
}

