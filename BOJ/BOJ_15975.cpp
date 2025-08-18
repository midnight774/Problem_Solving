#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 15975 화살표 그리기
풀이 방법 : 정렬
*/

int main()
{

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<int>> vecPos(N + 1);

	for (int i = 0; i < N; ++i)
	{
		int Pos, Color;
		cin >> Pos >> Color;

		vecPos[Color].push_back(Pos);
	}

	long long Ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		int Size = vecPos[i].size();
		if (Size > 1)
		{
			sort(vecPos[i].begin(), vecPos[i].end());

			for (int j = 1; j < Size - 1; ++j)
			{
				Ans += min(vecPos[i][j] - vecPos[i][j - 1], vecPos[i][j + 1] - vecPos[i][j]);
			}

			int sDist = vecPos[i][1] - vecPos[i][0];
			int lDist = vecPos[i][Size - 1] - vecPos[i][Size - 2];
			Ans += sDist + lDist;
		}
	}

	cout << Ans;
}

