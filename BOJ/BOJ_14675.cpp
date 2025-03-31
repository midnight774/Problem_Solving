#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 14675 단절점과 단절선
풀이 방법 : 트리

그려보고 직접 해보면 자식 수가 2 이상이면 단절점
트리는 사이클이 없기 때문에 모든 간선은 단절선임을 알 수 있다.
*/

int Cnt[100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		++Cnt[Src];
		++Cnt[Dest];
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int t;
		cin >> t;

		if (t == 1)
		{
			int Num;
			cin >> Num;

			if (Cnt[Num] == 1)
				cout << "no\n";

			else
				cout << "yes\n";
		}

		else
		{
			int Idx;
			cin >> Idx;
			
			cout << "yes\n";
		}
	}
}

