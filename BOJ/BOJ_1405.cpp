#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
BOJ 1405 미친 로봇
풀이 방법 : 백트래킹
*/

int N;
int DirY[4] = { 0,0,1,-1 };
int DirX[4] = { 1,-1,0,0 };
double Percent[4] = {};
int Board[29][29] = {};
bool Check[29][29] = {};
double Ans = 0.0;

void DFS(int CurY, int CurX, int MoveCnt, double CurPercent)
{
	if (MoveCnt == N)
	{
		Ans += CurPercent;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int NextY = CurY + DirY[i];
		int NextX = CurX + DirX[i];

		if (Check[NextY][NextX])
			continue;

		Check[NextY][NextX] = true;
		DFS(NextY, NextX, MoveCnt + 1, CurPercent * Percent[i]);
		Check[NextY][NextX] = false;
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < 4; ++i)
	{
		int Per;
		cin >> Per;
		Percent[i] = Per / 100.0;
	}
	
	Check[14][14] = true;
	DFS(14, 14, 0, 1.0);

	cout.precision(15);
	cout.fixed;
	cout << Ans;
}

