#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> vecNum;
vector<long long> vecTree;

long long Init(int Start, int End, int Node)
{
	if (Start == End)
	{
		vecTree[Node] = vecNum[Start];
		return vecTree[Node];
	}

	int Mid = (Start + End) / 2;

	vecTree[Node] = Init(Start, Mid, Node * 2) + Init(Mid + 1, End, Node * 2 + 1);
	return vecTree[Node];
}

long long Sum(int Start, int End, int Node, int Left, int Right)
{
	if (Left > End || Right < Start)
		return 0;

	if (Left <= Start && End <= Right)
		return vecTree[Node];

	int Mid = (Start + End) / 2;
	return Sum(Start, Mid, Node * 2, Left, Right) + Sum(Mid + 1, End, Node * 2 + 1, Left, Right);
}


void Update(int Start, int End, int Node, int Idx, long long Dif)
{
	if (Idx < Start || Idx > End)
		return;

	vecTree[Node] += Dif;

	if (Start == End)
		return;

	int Mid = (Start + End) / 2;
	Update(Start, Mid, Node * 2, Idx, Dif);
	Update(Mid + 1, End, Node * 2 + 1, Idx, Dif);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;

	vecNum.resize(N + 1);
	vecTree.resize((N + 1) * 4);

	for (int i = 1; i <= N; ++i)
	{
		cin >> vecNum[i];
	}

	Init(1, N, 1);

	for (int i = 0; i < Q; ++i)
	{
		long long x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y)
		{
			long long Tmp = x;
			x = y;
			y = Tmp;
		}

		cout << Sum(1, N, 1, x, y) << '\n';
		//a번째를 b로 바꾸는 것 -> 구현 코드는 Dif만큼 더해주는 것이기에
		Update(1, N, 1, a, b - vecNum[a]);
		vecNum[a] = b;
	}

}

