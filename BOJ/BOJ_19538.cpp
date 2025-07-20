#include <iostream>
#include <vector>
#include <queue>


using namespace std;

/*
BOJ 19538 루머
풀이 방법 : BFS, 위상정렬
*/

vector<int> vecGraph[200001] = {};
int BelieveCnt[200001] = {};
int Time[200001] = {};
bool IsTalked[200001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		Time[i] = -1;
		while (true)
		{
			int Input;
			cin >> Input;

			if (Input == 0)
				break;

			vecGraph[i].push_back(Input);
		}
	}
	

	int M;
	cin >> M;
	queue<int> qRumor;

	for (int i = 0; i < M; ++i)
	{
		int RumorStart;
		cin >> RumorStart;

		Time[RumorStart] = 0;
		qRumor.push(RumorStart);
	}


	int CurTime = 0;

	while (true)
	{
		if (qRumor.empty())
			break;

		++CurTime;
		queue<int> qNext;

		while (!qRumor.empty())
		{
			int Cur = qRumor.front();
			qRumor.pop();

			int Size = vecGraph[Cur].size();

			for (int i = 0; i < Size; ++i)
			{
				int Nei = vecGraph[Cur][i];
				++BelieveCnt[Nei];
				
				int Cnt = vecGraph[Nei].size();
				Cnt = Cnt / 2 + Cnt % 2;

				if (BelieveCnt[Nei] >= Cnt && Time[Nei] == -1)
				{
					Time[Nei] = CurTime;
					qNext.push(Nei);
				}
			}
		}

		qRumor = qNext;
	}

	for (int i = 1; i <= N; ++i)
		cout << Time[i] << ' ';
}

