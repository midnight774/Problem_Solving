#include <iostream>

/*
BOJ 3980 선발 명단
풀이 방법 : 백트래킹
*/

using namespace std;

bool Check[11] = {};
int Ability[11][11] = {};
int Answer = 0;

void DFS(int Depth, int Cnt, int Sum)
{
	if (Depth == 11)
	{
		if(Cnt == 11)
			Answer = max(Answer, Sum);

		return;
	}

	for (int i = 0; i < 11; ++i)
	{
		if (Ability[Depth][i] == 0)
			continue;

		if (Check[i])
			continue;

		Check[i] = true;

		DFS(Depth + 1, Cnt + 1, Sum + Ability[Depth][i]);

		Check[i] = false;
	}
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
		Answer = 0;

		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				cin >> Ability[i][j];
			}

			Check[i] = false;
		}

		DFS(0, 0, 0);

		cout << Answer << '\n';
	}

}
