#include <iostream>
#include <vector>
#include <queue>

/*
BOJ 15900 나무 탈출
풀이 방법 : BFS
 */

using namespace std;

vector<vector<int>> vecEdge;
bool Check[500001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vecEdge.resize(N + 1);

	for (int i = 0; i < N - 1; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		vecEdge[Src].push_back(Dest);
		vecEdge[Dest].push_back(Src);
	}

	queue<pair<int, int>> qInfo;
	pair<int, int> Start(1, 0);
	qInfo.push(Start);
	Check[1] = true;

	int Sum = 0;

	while (!qInfo.empty())
	{
		pair<int, int> Cur = qInfo.front();
		qInfo.pop();

		int Size = vecEdge[Cur.first].size();
		bool Enable = false;

		for (int i = 0; i < Size; ++i)
		{
			int NextNode = vecEdge[Cur.first][i];

			if (Check[NextNode])
				continue;

			Enable = true;
			Check[NextNode] = true;
			pair<int, int> Next = Cur;
			Next.first = NextNode;
			++Next.second;
			qInfo.push(Next);
		}

		if (!Enable)
			Sum += Cur.second;
	}

	if (Sum % 2 == 1)
		cout << "Yes";

	else
		cout << "No";
}

