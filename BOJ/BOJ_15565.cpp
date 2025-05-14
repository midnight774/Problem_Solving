#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 15565번 귀여운 라이언
풀이 방법 : 투 포인터
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> vecNum(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
	}

	int Left = 0;
	int Right = 0;
	int Cnt = 0;

	if (vecNum[0] == 1)
		++Cnt;

	int Answer = N + 1;
	while (Left <= Right && Left < N && Right < N)
	{
		if (Cnt == K)
		{
			Answer = min((Right + 1 - Left), Answer);
			if (vecNum[Left] == 1)
				--Cnt;

			++Left;
		}

		else
		{
			++Right;
			if (Right < N)
			{
				if (vecNum[Right] == 1)
					++Cnt;
			}
		}
	}

	if (Answer == N + 1)
		cout << -1;

	else
		cout << Answer;
	
}


