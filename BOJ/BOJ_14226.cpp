#include <iostream>
#include <vector>
#include <queue>

/*
BOJ 14226 이모티콘
풀이 방법 : BFS
*/

using namespace std;

bool Clip[1001][1001] = {};

struct ClipInfo
{
	int Clipboard = 0;
	int Num = 0;
	int Cnt = 0;
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	queue<ClipInfo> qInfo;
	ClipInfo Start;
	Start.Clipboard = 1;
	Start.Num = 1;
	Start.Cnt = 1;

	qInfo.push(Start);

	int Answer = 1001;

	while (!qInfo.empty())
	{
		ClipInfo Cur = qInfo.front();
		qInfo.pop();

		if (Cur.Num == N)
		{
			Answer = min(Answer, Cur.Cnt);
			continue;
		}

		if (Cur.Num - 1 > 1)
		{
			if (!Clip[Cur.Num - 1][Cur.Clipboard])
			{
				Clip[Cur.Num - 1][Cur.Clipboard] = true;
				ClipInfo Next2 = Cur;
				Next2.Num -= 1;
				Next2.Cnt += 1;
				qInfo.push(Next2);
			}
		}

		if (Cur.Num + Cur.Clipboard <= N)
		{
			if (!Clip[Cur.Num + Cur.Clipboard][Cur.Clipboard])
			{
				Clip[Cur.Num + Cur.Clipboard][Cur.Clipboard] = true;
				ClipInfo Next = Cur;
				Next.Num += Cur.Clipboard;
				Next.Cnt += 1;
				qInfo.push(Next);
			}

			if (!Clip[Cur.Num][Cur.Num])
			{
				Clip[Cur.Num][Cur.Num] = true;
				ClipInfo Next2 = Cur;
				Next2.Clipboard = Cur.Num;
				Next2.Cnt += 1;
				qInfo.push(Next2);
			}

		}
	}

	cout << Answer;
}

