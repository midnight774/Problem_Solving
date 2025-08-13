#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 1818 책정리
풀이 방법 : LIS (N log N)
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> vecNum(N);

	for (int i = 0; i < N; ++i)
		cin >> vecNum[i];

	vector<int> vecLis;
	vecLis.push_back(vecNum[0]);

	for (int i = 1; i < N; ++i)
	{
		int Size = vecLis.size();
		if (vecNum[i] > vecLis[Size - 1])
			vecLis.push_back(vecNum[i]);

		else
		{
			int Left = 0;
			int Right = Size - 1;

			while (Left <= Right)
			{
				int Mid = (Left + Right) / 2;

				if (vecLis[Mid] <= vecNum[i])
					Left = Mid + 1;

				else
					Right = Mid - 1;
			}

			vecLis[Left] = vecNum[i];
		}
	}
	
	cout << N - vecLis.size();


}

