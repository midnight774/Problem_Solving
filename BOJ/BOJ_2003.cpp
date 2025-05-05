#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 2003번 수들의 합
풀이 방법 : 누적 합
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vecNum(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> vecNum[i];

		vecNum[i] += vecNum[i - 1];
	}
	
	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j <= N; ++j)
		{
			if (vecNum[j] - vecNum[j - i] == M)
				++Cnt;
		}
	}


	cout << Cnt;
}


