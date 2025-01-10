#include <iostream>
#include <queue>

/*
BOJ 26215 눈 치우기
풀이 방법 : 우선순위 큐
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	priority_queue<int> pqNum;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		pqNum.push(Num);
	}

	int Time = 0;
	while (!pqNum.empty())
	{
		++Time;
		int TopNum = pqNum.top();
		pqNum.pop();

		if (pqNum.empty())
		{
			Time += TopNum - 1;
			break;
		}

		else
		{
			int NextTop = pqNum.top();
			pqNum.pop();

			if(NextTop > 1)
				pqNum.push(NextTop - 1);
		}

		if(TopNum > 1)
			pqNum.push(TopNum - 1);

	}

	if (Time > 1440)
		cout << -1;

	else
		cout << Time;
}
