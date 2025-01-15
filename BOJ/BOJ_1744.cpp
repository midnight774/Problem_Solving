#include <iostream>
#include <queue>

/*
BOJ 1744 수 묶기
풀이 방법 : 우선 순위 큐
 */

using namespace std;


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int ZeroCnt = 0;
	priority_queue<int, vector<int>, greater<>> pqMinus;
	priority_queue<int> pqPlus;

	int Answer = 0;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;

		if (Num > 0)
			pqPlus.push(Num);

		else if (Num == 0)
			++ZeroCnt;

		else
			pqMinus.push(Num);
	}

	while (!pqPlus.empty())
	{
		if (pqPlus.size() >= 2)
		{
			int Num = pqPlus.top();
			pqPlus.pop();

			if (pqPlus.top() == 1)
			{
				Answer += Num;
				Answer += pqPlus.top();
			}

			else
			{
				Answer += Num * pqPlus.top();
			}

			pqPlus.pop();
		}

		else
		{
			Answer += pqPlus.top();
			pqPlus.pop();
		}
	}

	while (!pqMinus.empty())
	{
		if (pqMinus.size() >= 2)
		{
			int Num = pqMinus.top();
			pqMinus.pop();
			Num *= pqMinus.top();
			pqMinus.pop();
			Answer += Num;
		}

		else
		{
			if (ZeroCnt > 0)
				--ZeroCnt;

			else
				Answer += pqMinus.top();

			pqMinus.pop();
		}
	}

	cout << Answer;
}
