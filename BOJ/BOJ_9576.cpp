#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 9576번 책 나눠주기
풀이 방법 : 그리디, 정렬
*/

bool Cmp(const pair<int, int>& Src, const pair<int, int> Dest)
{
	return Src.second < Dest.second;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T > 0)
	{
		--T;
		int N, M;
		cin >> N >> M;

		vector<bool> vecCheck(N + 1);
		vector<pair<int, int>> vecRange(M);
		for (int i = 0; i < M; ++i)
		{
			cin >> vecRange[i].first >> vecRange[i].second;
		}

		sort(vecRange.begin(), vecRange.end(), Cmp);

		int Cnt = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = vecRange[i].first; j <= vecRange[i].second; ++j)
			{
				if (!vecCheck[j])
				{
					vecCheck[j] = true;
					++Cnt;
					break;
				}
			}
		}

		cout << Cnt << '\n';
	}
	
}


