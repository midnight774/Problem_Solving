#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

/*
백준 2310 어드벤처 게임
풀이 방법 : DFS
*/

bool Enable = false;
bool Check[1001][501] = {};
struct RoomInfo
{
	char RoomType;
	int	 Gold;
	vector<int> vecDest;
};

void DFS(int CurPos, int CurGold, const int FinDest,
	const vector<RoomInfo>& vecRoom)
{
	if (Enable)
		return;

	if (CurPos == FinDest)
	{
		Enable = true;
		return;
	}

	int Size = vecRoom[CurPos].vecDest.size();

	for (int i = 0; i < Size; ++i)
	{
		int NextRoom = vecRoom[CurPos].vecDest[i];
		int NextGold = CurGold;

		if (vecRoom[NextRoom].RoomType == 'T')
		{
			NextGold -= vecRoom[NextRoom].Gold;

			if (NextGold < 0)
				continue;
		}

		else if (vecRoom[NextRoom].RoomType == 'L')
		{
			NextGold = max(CurGold, vecRoom[NextRoom].Gold);
		}
		
		if (Check[NextRoom][NextGold])
			continue;

		Check[NextRoom][NextGold] = true;
		DFS(NextRoom, NextGold, FinDest, vecRoom);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)
			break;

		vector<RoomInfo> vecRoom(N + 1);

		for (int i = 1; i <= N; ++i)
		{
			cin >> vecRoom[i].RoomType >> vecRoom[i].Gold;

			while (true)
			{
				int Room;
				cin >> Room;

				if (Room == 0)
					break;

				vecRoom[i].vecDest.push_back(Room);
			}
		}

		vecRoom[0].RoomType = 'E';
		vecRoom[0].Gold = 0;
		vecRoom[0].vecDest.push_back(1);

		DFS(0, 0, N, vecRoom);

		if (Enable)
			cout << "Yes\n";

		else
			cout << "No\n";

		Enable = false;
		memset(Check, 0, (N + 1) * 501);
	}
	
}
