#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

/*
백준 1497 기타 콘서트
풀이 방법 : 백 트래킹
*/

int N, M;
int Check[51] = {};
int MaxSong = 0;
int GuitarMinCnt[51] = {};
bool EnableSong[11][51] = {};

void DFS(int Depth, int GuitarCnt, int SongCnt)
{
	if (Depth == N)
	{
		if (SongCnt == 0)
			return;

		MaxSong = max(SongCnt, MaxSong);
		GuitarMinCnt[SongCnt] = min(GuitarMinCnt[SongCnt], GuitarCnt);

		return;
	}

	DFS(Depth + 1, GuitarCnt, SongCnt);

	int TempSongCnt = 0;
	for (int i = 0; i < M; ++i)
	{
		if (EnableSong[Depth][i])
		{
			if (Check[i] == 0)
				++TempSongCnt;

			++Check[i];
		}
	}

	if(TempSongCnt != 0)
		DFS(Depth + 1, GuitarCnt + 1, SongCnt + TempSongCnt);

	for (int i = 0; i < M; ++i)
	{
		if (EnableSong[Depth][i])
			--Check[i];
	}

}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Guitar, Song;
		cin >> Guitar >> Song;

		for (int j = 0; j < M; ++j)
		{
			if (Song[j] == 'Y')
				EnableSong[i][j] = true;

			else
			{
				EnableSong[i][j] = false;
			}
		}
	}

	for (int i = 1; i <= M; ++i)
		GuitarMinCnt[i] = N + 1;

	DFS(0, 0, 0);

	if (MaxSong == 0)
	{
		cout << -1;
	}

	else
	{
		cout << GuitarMinCnt[MaxSong];
	}

}
