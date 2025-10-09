#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

/*
BOJ 10282 해킹
풀이 방법 : 다익스트라
*/

struct ComInfo
{
	int ComNum;
	int Time;
};

struct DependenceInfo
{
	int DestCom;
	int Time;
};

struct cmp
{
	bool operator() (const ComInfo& Src, const ComInfo& Dest)
	{
		return Src.Time > Dest.Time;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	while(T>0)
	{
		--T;

		int N, D, C;
		cin >> N >> D >> C;

		vector<int> vecTime(N + 1, INT_MAX);
		vecTime[C] = 0;

		ComInfo Start;
		Start.ComNum = C;
		Start.Time = 0;

		vector<vector<DependenceInfo>> vecGraph(N + 1);

		for (int i = 0; i < D; ++i)
		{
			int a, b, s;
			cin >> a >> b >> s;
			DependenceInfo Info;
			Info.DestCom = a;
			Info.Time = s;
			vecGraph[b].push_back(Info);
		}

		priority_queue<ComInfo, vector<ComInfo>, cmp> pqInfo;
		pqInfo.push(Start);

		int AnsCnt = 1;
		int MaxTime = 0;
		while (!pqInfo.empty())
		{
			ComInfo Cur = pqInfo.top();
			pqInfo.pop();

			if (vecTime[Cur.ComNum] < Cur.Time)
				continue;

			int Size = vecGraph[Cur.ComNum].size();

			for (int i = 0; i < Size; ++i)
			{
				int Next = vecGraph[Cur.ComNum][i].DestCom;
				int NextTime = Cur.Time + vecGraph[Cur.ComNum][i].Time;

				if (vecTime[Next] <= NextTime)
					continue;

				if (vecTime[Next] == INT_MAX)
					++AnsCnt;

				vecTime[Next] = NextTime;

				ComInfo NextInfo;
				NextInfo.ComNum = Next;
				NextInfo.Time = NextTime;

				pqInfo.push(NextInfo);
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			if (vecTime[i] == INT_MAX)
				continue;

			MaxTime = max(MaxTime, vecTime[i]);
		}

		cout << AnsCnt << ' ' << MaxTime << '\n';

	}



}

