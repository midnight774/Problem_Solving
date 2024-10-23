#include <iostream>
#include <vector>
#include <algorithm>

/*
백준 2109번 순회강연
풀이 방법 : 정렬, 그리디
*/

using namespace std;

int Schedule[10001] = {};
bool Check[10001] = {};

struct cmp
{
	bool operator() (const pair<int, int>& Src, const pair<int, int>& Dest)
	{
		if (Src.first == Dest.first)
			return Src.second < Dest.second;

		return Src.first > Dest.first;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> vecInfo(N);
	int MaxDay = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> vecInfo[i].first >> vecInfo[i].second;
		MaxDay = max(MaxDay, vecInfo[i].second);
	}

	sort(vecInfo.begin(), vecInfo.end(), cmp());

	for (int i = 0; i < N; ++i)
	{
		int Day = vecInfo[i].second;
		int Price = vecInfo[i].first;

		while (Day > 0)
		{
			if (Schedule[Day] == 0)
			{
				Schedule[Day] = Price;
				break;
			}

			--Day;
		}
	}


	int Sum = 0;

	for (int i = 1; i <= MaxDay; ++i)
		Sum += Schedule[i];

	cout << Sum;
}
