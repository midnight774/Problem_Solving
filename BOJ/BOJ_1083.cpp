#include <iostream>
#include <vector>
#include <algorithm>

/*
BOJ 1083 소트
풀이 방법 : 그리디 (가능한 횟수 안에서 가장 큰 숫자 앞으로 끌고 오기)
*/

using namespace std;

bool Check[50] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecNum(N);

	for (int i = 0; i < N; ++i)
		cin >> vecNum[i];

	int S;
	cin >> S;

	vector<int> vecAnswer;

	while (S > 0)
	{
		int LeftCnt = -1;
		int Order = -1;
		int CurIdx = -1;
		int Max = 0;

		for (int i = 0; i < N; ++i)
		{
			if (Check[i])
				continue;

			++LeftCnt;

			if (LeftCnt > S)
				break;

			if (Max < vecNum[i])
			{
				CurIdx = i;
				Max = vecNum[i];
				Order = LeftCnt;
			}
		}

		if (Order == -1)
			break;

		Check[CurIdx] = true;
		vecAnswer.push_back(Max);
		S -= (Order);
	}

	for (int i = 0; i < N; ++i)
	{
		if (Check[i])
			continue;

		vecAnswer.push_back(vecNum[i]);
	}
	
	for (int i = 0; i < N; ++i)
	{
		cout << vecAnswer[i] << ' ';
	}
}
