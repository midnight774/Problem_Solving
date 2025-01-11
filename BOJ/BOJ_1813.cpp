#include <iostream>

/*
BOJ 1813 논리학 교수
풀이 방법 : 애드 혹
 */

using namespace std;

int Cnt[51] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		++Cnt[Num];
	}

	int Answer = -1;

	for (int i = 0; i < 51; ++i)
	{
		if (Cnt[i] == i)
			Answer = max(Answer, i);
	}

	cout << Answer;
}
