#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
BOJ 1450번 냅색 문제
풀이 방법 : Meet in the middle
*/

long long N, C;
vector<long long> vecWeight;
long long Ans = 0;
long long Sum = 0;

void DFS(const int Left, const int Right
	, int CurIdx, int CurWeight
	, vector<int>& vecComb)
{
	if (CurIdx == Right)
		return;

	if (CurWeight + vecWeight[CurIdx] <= C)
	{
		vecComb.push_back(CurWeight + vecWeight[CurIdx]);
		DFS(Left, Right, CurIdx + 1, CurWeight + vecWeight[CurIdx], vecComb);
	}

	DFS(Left, Right, CurIdx + 1, CurWeight, vecComb);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	
	vecWeight.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecWeight[i];
	}

	vector<int> vecLeft;
	vector<int> vecRight;

	vecLeft.push_back(0);
	vecRight.push_back(0);

	DFS(0, N / 2, 0, 0, vecLeft);
	DFS(N / 2, N, N / 2, 0, vecRight);

	sort(vecRight.begin(), vecRight.end());

	int Size = vecLeft.size();
	for (int i = 0; i < Size; ++i)
	{
		auto iter = upper_bound(vecRight.begin(), vecRight.end(), C - vecLeft[i]);
		int Cnt = upper_bound(vecRight.begin(), vecRight.end(), C - vecLeft[i]) - vecRight.begin();
		Ans += Cnt;
	}

	cout << Ans;
}


