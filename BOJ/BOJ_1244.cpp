#include <iostream>

/*
BOJ 1244 스위치 켜고 끄기
풀이 방법 : 구현
*/

using namespace std;

bool Switch[101] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Switch[i];
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int S, Num;
		cin >> S >> Num;

		if (S == 1)
		{
			int CurNum = Num;

			while (CurNum <= N)
			{
				Switch[CurNum] = !Switch[CurNum];
				CurNum += Num;
			}
		}

		else
		{
			int Offset = 0;

			while (true)
			{
				int TempOffset = Offset + 1;

				if (Num - TempOffset >= 1 && Num + TempOffset <= N)
				{
					if (Switch[Num - TempOffset] == Switch[Num + TempOffset])
					{
						Offset = TempOffset;
					}

					else
						break;
				}

				else
					break;
			}

			for (int i = Num - Offset; i <= Num + Offset; ++i)
			{
				Switch[i] = !Switch[i];
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << (int)Switch[i];

		if (i % 20 == 0)
			cout << '\n';

		else
			cout << ' ';
	}
}
