#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
BOJ 23843번 콘센트
풀이 방법 : 우선 순위 큐
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vecTime(N);
	for (int i = 0; i < N; ++i)
		cin >> vecTime[i];

	sort(vecTime.begin(), vecTime.end(), greater<>());

	priority_queue<int, vector<int>, greater<>> pqCon;

	for (int i = 0; i < N; ++i)
	{
		if (i == M)
			break;

		pqCon.push(vecTime[i]);
	}
	
	for (int i = M; i < N; ++i)
	{
		int Cur = pqCon.top();
		pqCon.pop();

		Cur += vecTime[i];
		pqCon.push(Cur);
	}

	int Max = 0;
	while (!pqCon.empty())
	{
		Max = max(pqCon.top(), Max);
		pqCon.pop();
	}
	cout << Max;
	
}

