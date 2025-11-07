#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 20055 컨베이어 벨트 위의 로봇 
풀이 방법 : 구현
*/

int Durability[201] = {};
bool Check[201] = {};

struct Info
{
	int Pos;
	int MoveDist;
};


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; ++i)
		cin >> Durability[i];

	queue<Info> qBelt;

	int Cnt = 0;
	int CurBelt = 2 * N;
	int Level = 0;

	while (Cnt < K)
	{
		++Level;
		int Size = qBelt.size();
		
		for (int i = 0; i < Size; ++i)
		{
			Info CurInfo = qBelt.front();
			qBelt.pop();

			++CurInfo.MoveDist;
			if (CurInfo.MoveDist == N - 1)
			{
				Check[CurInfo.Pos] = false;
				continue;
			}

			int NextBelt = CurInfo.Pos + 1;
			if (NextBelt == 2 * N + 1)
				NextBelt = 1;

			if (!Check[NextBelt] && Durability[NextBelt] > 0)
			{
				Check[CurInfo.Pos] = false;
				CurInfo.Pos = NextBelt;
				++CurInfo.MoveDist;
				--Durability[NextBelt];
				if (Durability[NextBelt] == 0)
					++Cnt;

				if (CurInfo.MoveDist == N - 1)
				{
					continue;
				}

				Check[NextBelt] = true;
			}

			qBelt.push(CurInfo);
		}

		if (Durability[CurBelt] > 0)
		{
			Check[CurBelt] = true;
			--Durability[CurBelt];
			Info I;
			I.MoveDist = 0;
			I.Pos = CurBelt;

			qBelt.push(I);

			if (Durability[CurBelt] == 0)
				++Cnt;
		}

		--CurBelt;
		if (CurBelt == 0)
			CurBelt = 2 * N;

	}

	cout << Level;
}

