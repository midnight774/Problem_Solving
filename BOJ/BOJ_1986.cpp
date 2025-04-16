#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 1986 체스
풀이 방법 : 구현
*/

bool Check[1001][1001] = {};
bool IsDanger[1001][1001] = {};

vector<pair<int, int>> vecKnight;
int KnightPosY[8] = { 2,1,-1,-2,2,1, -1,-2 };
int KnightPosX[8] = { 1,2,2,1,-1,-2,-2,-1 };

vector<pair<int, int>> vecQueen;
int QueenPosY[8] = { 1,1,1,0,0,-1,-1,-1 };
int QueenPosX[8] = { 1,0,-1,1,-1,1,0,-1 };

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int Y, X;
		cin >> Y >> X;

		IsDanger[Y][X] = true;
		Check[Y][X] = true;
		vecQueen.push_back(pair<int, int>(Y, X));
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int Y, X;
		cin >> Y >> X;

		IsDanger[Y][X] = true;
		Check[Y][X] = true;
		vecKnight.push_back(pair<int, int>(Y, X));
	}

	int P;
	cin >> P;
	for (int i = 0; i < P; ++i)
	{
		int Y, X;
		cin >> Y >> X;

		IsDanger[Y][X] = true;
		Check[Y][X] = true;
	}

	for (int i = 0; i < Q; ++i)
	{
		pair<int, int> CurPos = vecQueen[i];

		for (int j = 0; j < 8; ++j)
		{
			pair<int, int> TempPos = CurPos;
			TempPos.first += QueenPosY[j];
			TempPos.second += QueenPosX[j];

			while (true)
			{
				bool IsOut = TempPos.first <= 0 || TempPos.first > N ||
					TempPos.second <= 0 || TempPos.second > M;

				if (IsOut)
					break;

				if (Check[TempPos.first][TempPos.second])
					break;

				IsDanger[TempPos.first][TempPos.second] = true;
				TempPos.first += QueenPosY[j];
				TempPos.second += QueenPosX[j];
			}
		}
	}

	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			pair<int, int> TempPos = vecKnight[i];
			TempPos.first += KnightPosY[j];
			TempPos.second += KnightPosX[j];

			if (TempPos.first == 1 && TempPos.second == 1)
				cout << 111 << '\n';
		
			bool IsOut = TempPos.first <= 0 || TempPos.first > N ||
				TempPos.second <= 0 || TempPos.second > M;

			if (IsOut)
				continue;

			if (Check[TempPos.first][TempPos.second])
				continue;

			IsDanger[TempPos.first][TempPos.second] = true;

		}
	}

	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (!IsDanger[i][j])
				++Cnt;
		}
	}

	cout << Cnt;
}


