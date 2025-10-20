#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
BOJ 31964 반품 회수
풀이 방법 : 그리디

어차피 시작점으로 돌아와야하므로 
갔다가 왔다가 한번씩 돌리자
가는 길에 꺼내져 있으면 바로 회수
오는 길에는 꺼내져 있을 때까지 기다리고 회수

*/

bool Check[100000001] = {};
struct Info
{
	int Pos;
	int Time;
};

struct cmp
{
	bool operator() (const Info& Src, const Info& Dest)
	{
		return Src.Pos < Dest.Pos;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	vector<Info> vecInfo(N);
	for (int i = 0; i < N; ++i)
		cin >> vecInfo[i].Pos;

	for (int i = 0; i < N; ++i)
		cin >> vecInfo[i].Time;
	
	sort(vecInfo.begin(), vecInfo.end(), cmp());
	
	int Time = 0;
	int CurPos = 0;
	for (int i = 0; i < N; ++i)
	{
		if (vecInfo[i].Time <= Time + (vecInfo[i].Pos - CurPos))
		{
			Check[vecInfo[i].Pos] = true;
			Time += vecInfo[i].Pos - CurPos;
			CurPos = vecInfo[i].Pos;
		}

	}

	for (int i = N - 1; i >= 0; --i)
	{
		if (Check[vecInfo[i].Pos])
			continue;

		int Dist = abs(vecInfo[i].Pos - CurPos);
		Time = max(vecInfo[i].Time, Time + Dist);
		CurPos = vecInfo[i].Pos;
	}

	Time += CurPos;
	cout << Time;
}

