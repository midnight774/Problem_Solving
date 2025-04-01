#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 3078 좋은 친구
풀이 방법 : 슬라이딩 윈도우
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<int> vecPlace(N + 1);

	vector<int> vecCnt(21);
	long long Answer = 0;

	for (int i = 0; i < N; ++i)
	{
		string Name;
		cin >> Name;
		vecPlace[i] = (int)Name.length();

		if (i <= K)
			++vecCnt[vecPlace[i]];
	}
	
	for (int i = 1; i <= 20; ++i)
	{
		long long Pair = vecCnt[i] * (vecCnt[i] - 1);
		Pair /= 2;
		Answer += Pair;
	}

	for (int i = 1; i < N - K; ++i)
	{
		--vecCnt[vecPlace[i - 1]];
		
		Answer += vecCnt[vecPlace[i + K]];
		
		++vecCnt[vecPlace[i + K]];
	}

	cout << Answer;
}

