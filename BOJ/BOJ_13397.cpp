#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 13397번 구간 나누기 2
풀이 방법 : 이분 탐색

최댓값 최솟값 갱신 시켜가면서 선형탐색 해주면서
최대 - 최소 > Mid 값이 되는 순간 그 구간을 하나의 구간으로 만들어준다.
즉, 최대 - 최소 값이 Mid보다 작은 구간을 가능한대로 만들어본다.
끝까지 한 뒤 만들어진 구간의 갯수가 M개보다 작을 경우
해당 Mid값이 가능한 값이라는 뜻

*/

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


	int Answer = 1000000;
	int Left = 0;
	int Right = *max_element(vecNum.begin(), vecNum.end());

	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		int TempMax = 0;
		int TempMin = 10001;

		int Cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			TempMax = max(TempMax, vecNum[i]);
			TempMin = min(TempMin, vecNum[i]);

			if (TempMax - TempMin > Mid)
			{
				++Cnt;
				TempMax = vecNum[i];
				TempMin = vecNum[i];
			}
		}

		if (Cnt < M)
		{
			Answer = Mid;
			Right = Mid - 1;
		}

		else
		{
			Left = Mid + 1;
		}
	}

	cout << Answer;
	
}


