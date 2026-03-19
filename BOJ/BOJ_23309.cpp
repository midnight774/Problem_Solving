#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 23309 철도 공사
풀이 방법 : 연결 리스트, 구현

*/

struct StationNode
{
	int Prev;
	int Next;
};

StationNode Station[1000001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vecNum(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
	}


	for (int i = 0; i < N; ++i)
	{
		int PrevIdx = i - 1;
		if (PrevIdx < 0)
			PrevIdx = N - 1;
		
		int NextIdx = i + 1;
		if (NextIdx == N)
			NextIdx = 0;

		Station[vecNum[i]].Prev = vecNum[PrevIdx];
		Station[vecNum[i]].Next = vecNum[NextIdx];
	}

	for (int i = 0; i < M; ++i)
	{
		string Cmd;
		int iNum, jNum;

		cin >> Cmd;

		if (Cmd == "BN")
		{
			cin >> iNum >> jNum;
			int CurIdx = iNum;
			int NextStation = Station[iNum].Next;
			cout << NextStation << '\n';

			int NewStation = jNum;
			Station[jNum].Next = NextStation;
			Station[jNum].Prev = iNum;

			Station[iNum].Next = jNum;
			Station[NextStation].Prev = jNum;
			
		}

		else if (Cmd == "BP")
		{
			cin >> iNum >> jNum;
			int CurIdx = iNum;
			int PrevStation = Station[iNum].Prev;
			cout << PrevStation << '\n';

			int NewStation = jNum;
			Station[jNum].Next = iNum;
			Station[jNum].Prev = PrevStation;

			Station[iNum].Prev = jNum;
			Station[PrevStation].Next= jNum;
		}

		else if (Cmd == "CN")
		{
			cin >> iNum;
			int CurIdx = iNum;
			int NextStation = Station[iNum].Next;
			cout << NextStation << '\n';

			int PrevStation = iNum;
			int NNextStation = Station[NextStation].Next;

			Station[PrevStation].Next = NNextStation;
			Station[NNextStation].Prev = PrevStation;
		}

		else if (Cmd == "CP")
		{
			cin >> iNum;

			int CurIdx = iNum;
			int PrevStation = Station[iNum].Prev;
			cout << PrevStation << '\n';

			int NextStation = iNum;
			int PPrevStation = Station[PrevStation].Prev;

			Station[PPrevStation].Next = NextStation;
			Station[NextStation].Prev = PPrevStation;
		}
	}

}




