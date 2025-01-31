#include <iostream>
/*
BOJ 1593 문자 해독
풀이 방법 : 슬라이딩 윈도우
 */

using namespace std;

int WCnt[128] = {};
int CurCnt[128] = { };

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int g, s;
	cin >> g >> s;

	string W, S;
	cin >> W >> S;

	for (int i = 0; i < g; ++i)
	{
		++WCnt[(int)W[i]];
		++CurCnt[(int)S[i]];
	}

	int Cnt = 0;

	for (int i = 0; i <= s - g; ++i)
	{
		bool Enable = true;
		for (int j = 0; j < g; ++j)
		{
			if (WCnt[(int)W[j]] != CurCnt[(int)W[j]])
			{
				Enable = false;
				break;
			}
		}

		if (Enable)
			++Cnt;

		--CurCnt[(int)S[i]];

		if(i + g <= s)
			++CurCnt[(int)S[i + g]];
	}

	cout << Cnt;

}

