#include <iostream>
#include <vector>
#include <stack>

/*
BOJ 12789 도키도키 간식드리미
풀이 방법 : 스택
*/

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecStudent(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecStudent[i];
	}
	
	stack<int> sNum;

	int CurOrder = 1;

	for (int i = 0; i < N; ++i)
	{
		int CurNum = vecStudent[i];
		bool IsPushed = false;

		if (CurNum == CurOrder)
		{
			++CurOrder;
			IsPushed = true;
		}

		else if (sNum.empty())
		{
			sNum.push(CurNum);
			continue;
		}

		while (!sNum.empty())
		{
			if (sNum.top() == CurOrder)
			{
				++CurOrder;
				sNum.pop();
			}

			else
			{
				if (!IsPushed)
					sNum.push(CurNum);

				break;
			}
		}
	}

	if (CurOrder == N + 1)
		cout << "Nice";

	else
		cout << "Sad";
}
