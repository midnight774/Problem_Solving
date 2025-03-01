#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 19638 센티와 마법의 뿅망치
풀이 방법 : 우선순위 큐
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, H, T;
	cin >> N >> H >> T;

	priority_queue<int> pqHeight;
	for (int i = 0; i < N; ++i)
	{
		int Height;
		cin >> Height;
		pqHeight.push(Height);
	}

	int Cnt = 0;
	bool Enable = false;
	while (T> 0)
	{
		--T;
		int Cur = pqHeight.top();
		pqHeight.pop();

		if (Cur < H)
		{
			Enable = true;
			break;
		}

		if (Cur == 1)
		{
			pqHeight.push(Cur);
			break;
		}

		Cur /= 2;
		++Cnt;

		pqHeight.push(Cur);
	}

	if (pqHeight.top() < H)
		Enable = true;

	if (Enable)
	{
		cout << "YES\n";
		cout << Cnt;
	}

	else
	{
		cout << "NO\n";
		cout << pqHeight.top();
	}

}

