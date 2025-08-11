#include <iostream>
#include <queue>

using namespace std;

/*
BOJ 1655 가운데를 말해요
풀이 방법 : 우선순위 큐
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int Idx = 0;
	int CurNum;
	cin >> CurNum;
	cout << CurNum << '\n';

	priority_queue<int> pqLeft;
	priority_queue<int, vector<int>, greater<>> pqRight;

	for (int i = 2; i <= N; ++i)
	{
		int Num;
		cin >> Num;

		if (CurNum <= Num)
			pqRight.push(Num);

		else
			pqLeft.push(Num);

		if (pqRight.size() > i / 2)
		{
			pqLeft.push(CurNum);
			CurNum = pqRight.top();
			pqRight.pop();
		}

		else if (pqRight.size() < i / 2)
		{
			pqRight.push(CurNum);
			CurNum = pqLeft.top();
			pqLeft.pop();
		}

		cout << CurNum << '\n';
	}
}

