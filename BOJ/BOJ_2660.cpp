#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 2660 회장 뽑기
풀이 방법 : 워셜 플로이드
*/

int Max = 987654321;
int Score[51][51] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
				continue;
			Score[i][j] = Max;
		}
	}

	while (true)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		if (Src == -1 && Dest == -1)
			break;

		Score[Src][Dest] = 1;
		Score[Dest][Src] = 1;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == k || j == k)
					continue;
				if (Score[i][k] == Max || Score[k][j] == Max)
					continue;

				Score[i][j] = min(Score[i][j], Score[i][k] + Score[k][j]);
			}
		}
	}

	int MinScore = Max;
	vector<int> vecIdx;

	for (int i = 1; i <= N; ++i)
	{
		int CurScore = 1;
		for (int j = 1; j <= N; ++j)
		{
			CurScore = max(CurScore, Score[i][j]);
		}

		if (CurScore < MinScore)
		{
			MinScore = CurScore;
			vecIdx.clear();
			vecIdx.push_back(i);
		}

		else if (CurScore == MinScore)
		{
			vecIdx.push_back(i);
		}
	}
	sort(vecIdx.begin(), vecIdx.end());

	int Size = vecIdx.size();

	cout << MinScore << ' ' << Size << '\n';
	for (int i = 0; i < Size; ++i)
	{
		cout << vecIdx[i] << ' ';
	}
	
}

