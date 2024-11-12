#include <iostream>
#include <cmath>

/*
BOJ 14891 톱니바퀴
풀이 방법 : 구현
*/

using namespace std;

int Idx[4] = { 0,0,0,0 };
string Wheel[4] = {};
bool Check[4] = {};

void Rotate(int RotIdx, int Dir)
{
	int LeftIdx = RotIdx - 1;
	int CurUp = Idx[RotIdx];

	if (LeftIdx >= 0)
	{
		int CurLeft = (CurUp + 6) % 8;

		int LeftUp = Idx[LeftIdx];
		int LeftRight = (LeftUp + 2) % 8;

		if (Wheel[RotIdx][CurLeft] != Wheel[LeftIdx][LeftRight] && !Check[LeftIdx])
		{
			Check[LeftIdx] = true;
			Rotate(LeftIdx, -Dir);
		}
	}

	int RightIdx = RotIdx + 1;
	if (RightIdx < 4)
	{
		int CurRight = (CurUp + 2) % 8;

		int RightUp = Idx[RightIdx];
		int RightLeft = (RightUp + 6) % 8;

		if (Wheel[RotIdx][CurRight] != Wheel[RightIdx][RightLeft] && !Check[RightIdx])
		{
			Check[RightIdx] = true;
			Rotate(RightIdx, -Dir);
		}
	}

	Idx[RotIdx] += (-Dir);

	if (Idx[RotIdx] < 0)
		Idx[RotIdx] = 7;

	else
		Idx[RotIdx] %= 8;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);


	for (int i = 0; i < 4; ++i)
	{
		cin >> Wheel[i];
	}


	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int RotIdx, RotDir;
		cin >> RotIdx >> RotDir;

		Check[RotIdx - 1] = true;
		Rotate(RotIdx - 1, RotDir);

		for (int j = 0; j < 4; ++j)
			Check[j] = false;
	}

	int Score = 0;
	for (int i = 0; i < 4; ++i)
	{
		int CurUp = Idx[i];
		if (Wheel[i][CurUp] == '1')
		{
			Score += pow(2, i);
		}
	}

	cout << Score;
}
