#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 7571 점 모으기
풀이 방법 : 정렬, 중앙값
*/


bool CmpX(const pair<int,int>& Src, const pair<int,int>& Dest)
{
	return Src.first < Dest.first;
}

bool CmpY(const pair<int, int>& Src, const pair<int, int>& Dest)
{
	return Src.second < Dest.second;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>>vecPos(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;

	}


	sort(vecPos.begin(), vecPos.end(), CmpX);
	int TargetX = vecPos[M / 2].first;

	sort(vecPos.begin(), vecPos.end(), CmpY);
	int TargetY = vecPos[M / 2].second;

	int Cost = 0;
	for (int i = 0; i < M; ++i)
	{
		int TempCost = abs(vecPos[i].first - TargetX) + abs(vecPos[i].second - TargetY);
		Cost += TempCost;
	}

	cout << Cost;


}


