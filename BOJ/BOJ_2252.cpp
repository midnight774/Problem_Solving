#include <iostream>
#include <vector>
#include <queue>

/*
BOJ_2252 줄 세우기
풀이 방법 : 위상정렬
*/

using namespace std;

int InCnt[32001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> vecStudent(N + 1);
	queue<int> qStudent;
	vector<int> vecAnswer;

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;
		++InCnt[Dest];

		vecStudent[Src].push_back(Dest);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (InCnt[i] == 0)
			qStudent.push(i);
	}

	while (!qStudent.empty())
	{
		int CurStudent = qStudent.front();
		qStudent.pop();
		vecAnswer.push_back(CurStudent);

		int Size = vecStudent[CurStudent].size();

		for (int i = 0; i < Size; ++i)
		{
			int Next = vecStudent[CurStudent][i];
			--InCnt[Next];

			if (InCnt[Next] == 0)
				qStudent.push(Next);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << vecAnswer[i] << ' ';
	}
}
