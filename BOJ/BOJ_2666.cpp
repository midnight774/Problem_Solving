#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 2666 벽장문의 이동
풀이 방법 : 재귀
*/

int N;
int Length;
int Ans = 4001;
void DFS(int Depth, int MoveCnt
	, int Open1, int Open2
	, const vector<int>& vecUse)
{
	if (Depth == Length)
	{
		Ans = min(Ans, MoveCnt);
		return;
	}

	DFS(Depth + 1, MoveCnt + abs(vecUse[Depth] - Open1), vecUse[Depth], Open2, vecUse);
	DFS(Depth + 1, MoveCnt + abs(vecUse[Depth] - Open2), Open1, vecUse[Depth], vecUse);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	int Open1, Open2;
	cin >> Open1 >> Open2;

	cin >> Length;
	vector<int> vecUse(Length);
	for (int i = 0; i < Length; ++i)
	{
		cin >> vecUse[i];
	}

	DFS(0, 0, Open1, Open2, vecUse);

	cout << Ans;
}

