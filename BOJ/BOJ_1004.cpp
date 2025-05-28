
#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 1004번 어린 왕자
풀이 방법 : 기하학
*/

bool SrcCheck[51] = {};
bool DestCheck[51] = {};

bool IsIn(int CurX, int CurY, int CenterX, int CenterY, int Radius)
{
	int Dist = (CenterX - CurX) * (CenterX - CurX) + (CenterY - CurY) * (CenterY - CurY);

	return Dist <= Radius * Radius;
}

struct Info
{
	int X;
	int Y;
	int Radius;
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

		int StartX, StartY, EndX, EndY;
		cin >> StartX >> StartY >> EndX >> EndY;

		int N;
		cin >> N;

		vector<Info> vecPos(N);

		for (int i = 0; i < N; ++i)
		{
			cin >> vecPos[i].X >> vecPos[i].Y >>vecPos[i].Radius;
			SrcCheck[i] = false;
			DestCheck[i] = false;
		}

		int Cnt = 0;

		for (int i = 0; i < N; ++i)
		{
			if (IsIn(StartX, StartY, vecPos[i].X, vecPos[i].Y, vecPos[i].Radius))
				SrcCheck[i] = true;

			if (IsIn(EndX, EndY, vecPos[i].X, vecPos[i].Y, vecPos[i].Radius))
				DestCheck[i] = true;

			if (SrcCheck[i] != DestCheck[i])
				++Cnt;

		}
	
		cout << Cnt << '\n';
	}
}

