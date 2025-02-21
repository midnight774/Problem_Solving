#include <iostream>
#include <vector>
#include <set>

/*
BOJ 1091 카드 섞기
풀이 방법 : 구현
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecCur(N);
	vector<int> vecTarget(N);
	vector<int> vecShuffle(N);

	for (int i = 0; i < N; ++i)
	{
		vecCur[i] = i;
		cin >> vecTarget[i];
	}

	for (int i = 0; i < N; ++i)
		cin >> vecShuffle[i];

	int Cnt = 0;
	bool Enable = false;

	vector<int> vecStart = vecCur;
	while (true)
	{
		bool Same = true;
		for (int i = 0; i < N; ++i)
		{
			if (vecTarget[vecCur[i]] != i % 3)
			{
				Same = false;
				break;
			}
		}

		if (Same)
		{
			cout << Cnt;
			Enable = true;
			break;
		}

		vector<int> Next(N);
		for (int i = 0; i < N; ++i)
		{
			Next[vecShuffle[i]] = vecCur[i];
		}

		if (vecStart == Next)
			break;

		++Cnt;
		vecCur = Next;
	}


	if (!Enable)
		cout << -1;
}

