#include <iostream>

using namespace std;

/*
백준 2118번 두 개의 탑

풀이 방법 : 누적 합, 투 포인터
*/

int Dist[50001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Dist[i];
		Dist[i] += Dist[i - 1];
	}

	int Left = 1;
	int Right = 2;
	int Max = 0;

	while (Left <= Right && Right <= N)
	{
		int ClockWise = Dist[Right] - Dist[Left - 1];
		int AntiClock = Dist[N] - ClockWise;

		int TempDist = min(ClockWise, AntiClock);
		Max = max(TempDist, Max);

		if (ClockWise <= AntiClock)
		{
			++Right;
		}

		else
		{
			++Left;
		}
	}

	cout << Max;
}
