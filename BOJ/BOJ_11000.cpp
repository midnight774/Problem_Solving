#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
백준 11000 강의실 배정
풀이 방법 : 그리디 (우선순위 큐)
*/

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> vecClass(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecClass[i].first >> vecClass[i].second;
	}

	priority_queue<int,vector<int>, greater<>> pqEnd;
	sort(vecClass.begin(), vecClass.end());


	for (int i = 0; i < N; ++i)
	{
		bool Enable = false;

		if (!pqEnd.empty())
		{
			if (pqEnd.top() <= vecClass[i].first)
			{
				pqEnd.pop();
				pqEnd.push(vecClass[i].second);
				Enable = true;
			}
		}

		if(!Enable)
		{
			pqEnd.push(vecClass[i].second);
		}
		
	}

	cout << pqEnd.size();

}
