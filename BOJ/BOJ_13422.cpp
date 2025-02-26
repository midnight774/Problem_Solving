#include <iostream>
#include <vector>

using namespace std;

/*
백준 13422 도둑
풀이 방법 : 슬라이딩 윈도우

N == M 일 경우 같은 경우를 N번 카운팅 안하도록 주의
*/

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

		int N, M, K;
		cin >> N >> M >> K;

		vector<int> vecMoney(N);
		for (int i = 0; i < N; ++i)
			cin >> vecMoney[i];

		int Cnt = 0;
		int CurMoney = 0;
		for (int i = 0; i < M; ++i)
		{
			CurMoney += vecMoney[i];
		}
		
		if (CurMoney < K)
			++Cnt;

		if(N != M)
		{
			for (int i = 1; i < N; ++i)
			{
				CurMoney -= vecMoney[i - 1];
				CurMoney += vecMoney[(i + M - 1) % N];

				if (CurMoney < K)
					++Cnt;
			}
		}

		cout << Cnt << '\n';
	}
}

