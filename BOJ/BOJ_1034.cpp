#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 1034 램프
풀이 방법 : 브루트 포스, 애드 혹

열 단위로 켜므로 행의 패턴이 같으면 같이 켜진다.
켜질 수 있는 행을 찾아서 그 행과 같은 패턴의 행의 갯수의 최댓값을 구한다.
*/

int N, M;
int K;
string Lamp[51] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> Lamp[i];
	}

	cin >> K;

	int Answer = 0;
	for (int i = 0; i < N; ++i)
	{
		int ZeroCnt = 0;

		for (int j = 0; j < M; ++j)
		{
			if (Lamp[i][j] == '0')
				++ZeroCnt;
		}

		if (ZeroCnt % 2 == K % 2 && ZeroCnt <= K)
		{
			int TempCnt = 0;

			for (int j = 0; j < N; ++j)
			{
				if (Lamp[i] == Lamp[j])
					++TempCnt;
			}

			Answer = max(Answer, TempCnt);
		}
		
	}

	cout << Answer;
	
}


