#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 2610 회의준비
풀이 방법 : 워셜 플로이드, 분리집합
*/

bool IsCounted[101] = {};
int Time[101][101] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			Time[i][j] = 1001;

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		Time[Src][Dest] = 1;
		Time[Dest][Src] = 1;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == j || j == k || i == k)
					continue;

				if (Time[i][k] == 1001 || Time[k][j] == 1001)
					continue;

				Time[i][j] = min(Time[i][k] + Time[k][j], Time[i][j]);
			}
		}
	}

	vector<int> vecAnswer;

	for (int i = 1; i <= N; ++i)
	{
		if (IsCounted[i])
			continue;

		IsCounted[i] = true;
		vector<int> vecNum;
		vecNum.push_back(i);

		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
				continue;

			if (Time[i][j] == 1001)
				continue;

			if (IsCounted[j])
				continue;

			IsCounted[j] = true;

			vecNum.push_back(j);
		}

		int MinIdx = -1;
		int Min = 987654321;

		for (int j = 0; j < vecNum.size(); ++j)
		{
			int CurIdx = vecNum[j];
			int TempTime = 0;

			for (int k = 0; k < vecNum.size(); ++k)
			{
				if (j == k)
					continue;

				int DestIdx = vecNum[k];
				TempTime = max(TempTime, Time[CurIdx][DestIdx]);
			}

			if (TempTime < Min)
			{
				Min = TempTime;
				MinIdx = CurIdx;
			}
		}

		vecAnswer.push_back(MinIdx);
	}

	sort(vecAnswer.begin(), vecAnswer.end());
	cout << vecAnswer.size() << '\n';
	for (int i = 0; i < vecAnswer.size(); ++i)
	{
		cout << vecAnswer[i] << '\n';
	}
}


