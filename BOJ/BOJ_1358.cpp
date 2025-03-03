#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/*
BOJ 1358 하키 
풀이 방법 : 기하학
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int W, H, X, Y, P;
	cin >> W >> H >> X >> Y >> P;
	
	int Right = X + W;
	int Top = H + Y;

	vector<pair<int, int>> vecPos(P);
	for (int i = 0; i < P; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	int Cnt = 0;

	for (int i = 0; i < P; ++i)
	{
		if (vecPos[i].first < X)
		{
			int CenterX = X;
			int CenterY = Y + H / 2;

			int Dist = (vecPos[i].first - CenterX) * (vecPos[i].first - CenterX);
			Dist += (vecPos[i].second - CenterY) * (vecPos[i].second - CenterY);

			if (Dist <= H * H / 4)
			{
				++Cnt;
			}
		}

		else if (vecPos[i].first > Right)
		{
			int CenterX = Right;
			int CenterY = Top - H / 2;

			int Dist = (vecPos[i].first - CenterX) * (vecPos[i].first - CenterX);
			Dist += (vecPos[i].second - CenterY) * (vecPos[i].second - CenterY);

			if (Dist <= H * H / 4)
			{
				++Cnt;
			}
		}

		else
		{
			if (vecPos[i].first <= Right && vecPos[i].first >= X
				&& vecPos[i].second <= Top && vecPos[i].second >= Y)
				++Cnt;
		}
	}

	cout << Cnt;
}

