#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
BOJ 18352 특정 거리의 도시 찾기
풀이 방법 : BFS
*/

bool Check[300001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> vecCity(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		vecCity[Src].push_back(Dest);
	}

	queue<pair<int,int>> qPos;
	qPos.push(pair<int,int>(X, 0));

	Check[X] = true;
	vector<int> vecAnswer;

	while (!qPos.empty())
	{
		pair<int, int> Cur = qPos.front();
		qPos.pop();

		int Size = vecCity[Cur.first].size();

		for (int i = 0; i < Size; ++i)
		{
			int Next = vecCity[Cur.first][i];
			if (Check[Next])
				continue;

			Check[Next] = true;

			if (Cur.second + 1 == K)
				vecAnswer.push_back(Next);

			qPos.push(pair<int, int>(Next, Cur.second + 1));
		}
	}

	sort(vecAnswer.begin(), vecAnswer.end());


	if (vecAnswer.empty())
		cout << -1;
	for (int i = 0; i < vecAnswer.size(); ++i)
	{
		cout << vecAnswer[i] << '\n';
	}
}

