#include <iostream>
#include <vector>

/*
BOJ 17266 어두운 굴다리
풀이 방법 : 이분 탐색
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vecPos(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> vecPos[i];
	}
	
	int Left = 1;
	int Right = N;
	int Answer = N;

	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		int CurRightPos = 0;

		bool IsSucceeded = false;
		for (int i = 0; i < M; ++i)
		{
			int CurPos = vecPos[i];

			if (CurPos - Mid > CurRightPos)
				break;

			CurRightPos = CurPos + Mid;
			
		}

		if (CurRightPos >= N)
		{
			IsSucceeded = true;
		}

		if (IsSucceeded)
		{
			Answer = min(Answer, Mid);
			Right = Mid - 1;
		}

		else
		{
			Left = Mid + 1;
		}
	}

	cout << Answer;
}
