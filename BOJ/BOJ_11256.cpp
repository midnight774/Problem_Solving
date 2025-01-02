#include <iostream>
#include <vector>
#include <algorithm>

/* 
BOJ 11256 사탕
풀이 방법 : 정렬
*/

using namespace std;


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

		int J, N;
		cin >> J >> N;

		vector<int> vecArea(N);
		for (int i = 0; i < N; ++i)
		{
			int R, C;
			cin >> R >> C;
			vecArea[i] = R * C;
		}

		sort(vecArea.begin(), vecArea.end(), greater<>());

		for (int i = 0; i < N; ++i)
		{
			J -= vecArea[i];

			if (J <= 0)
			{
				cout << i + 1 << '\n';
				break;
			}
		}
	}

}
