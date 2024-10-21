#include <iostream>
#include <vector>

using namespace std;

/*
백준 3020 개똥벌레
풀이 방법 : 누적 합
*/

int UpCnt[500001] = {};
int DownCnt[500001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, H;
	cin >> N >> H;

	vector<int> vecUp;
	vector<int> vecDown;
	for (int i = 1; i <= N; ++i)
	{
		int Height;
		cin >> Height;

		if (i % 2 == 1)
		{
			vecUp.push_back(Height);
		}

		else
			vecDown.push_back(Height);
	}
	
	for (int i = 0; i < N / 2; ++i)
		++DownCnt[vecDown[i]];

	for (int i = H-1; i >= 1; --i)
		DownCnt[i] += DownCnt[i + 1];

	for (int i = 0; i < N / 2; ++i)
		++UpCnt[H - (vecUp[i] - 1)];

	for (int i = 1; i <= H; ++i)
		UpCnt[i] += UpCnt[i - 1];

	int AnswerMin = 50000001;
	int AnswerCnt = 1;
	for (int i = 1; i <= H; ++i)
	{
		if (AnswerMin > UpCnt[i] + DownCnt[i])
		{
			AnswerMin = UpCnt[i] + DownCnt[i];
			AnswerCnt = 1;
		}

		else if (AnswerMin == UpCnt[i] + DownCnt[i])
			++AnswerCnt;
	}

	cout << AnswerMin << ' ' << AnswerCnt;
}
