#include <iostream>
#include <vector>
using namespace std;

int Root[50001] = {};
int Level[50001] = {};
vector<vector<int>> vecTree;

void InitTree(int Node, int Parent)
{
	Root[Node] = Parent;
	Level[Node] = Level[Parent] + 1;

	int Size = vecTree[Node].size();
	for (int i = 0; i < Size; ++i)
	{
		int ChildNode = vecTree[Node][i];

		if (ChildNode == Parent)
			continue;

		InitTree(ChildNode, Node);
	}
}

int LCA(int Src, int Dest)
{
	if (Level[Src] > Level[Dest])
	{
		int Temp = Dest;
		Dest = Src;
		Src = Temp;
	}

	if (Src == Root[Dest])
		return Root[Dest];

	else
		return LCA(Src, Root[Dest]);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vecTree.resize(N + 1);

	for (int i = 0; i < N - 1; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		vecTree[Src].push_back(Dest);
		vecTree[Dest].push_back(Src);
	}

	InitTree(1, 0);

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		if (Src == Dest)
		{
			cout << Src << '\n';
			continue;
		}

		int Answer = LCA(Src, Dest);
		cout << Answer << '\n';

	}

}
