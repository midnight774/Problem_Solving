#include <iostream>
#include <queue>
#include <algorithm>

/* 
BOJ 1374 강의실
풀이 방법 : 정렬, 우선순위 큐
*/

using namespace std;


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	vector<pair<int, int>> vecLecture(N);
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num >> vecLecture[i].first >> vecLecture[i].second;
	}

	sort(vecLecture.begin(), vecLecture.end());

	priority_queue<int, vector<int>, greater<>> qEndTime;
	qEndTime.push(vecLecture[0].second);

	for (int i = 1; i < N; ++i)
	{
		if (qEndTime.top() <= vecLecture[i].first)
		{
			qEndTime.pop();
		}

		qEndTime.push(vecLecture[i].second);
		
	}

	cout << qEndTime.size();
}
