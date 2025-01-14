#include <iostream>
#include <vector>

/*
BOJ 20303 할로윈의 양아치
풀이 방법 : 분리 집합 + 배낭 채우기
유니온 파인드로 친구 집합을 구한 뒤 이를 통해 0-1 배낭 채우기 수행
 */

using namespace std;

int Answer = 0;
int N, M, K;
int Root[30001] = {};
int CandyCnt[30001] = {};
int FriendCnt[30001] = {};
int DP[30001][3001] = {};
bool Check[30001] = {};
bool IsRoot[30001] = {};
vector<int> vecRoots;

int Find(int Num)
{
	if (Root[Num] == Num)
		return Root[Num];

	Root[Num] = Find(Root[Num]);
		
	return Root[Num];
}

void Union(int Src, int Dest)
{
	int SrcRoot = Find(Src);
	int DestRoot = Find(Dest);

	if (SrcRoot == DestRoot)
		return;

	FriendCnt[SrcRoot] += FriendCnt[DestRoot];
	CandyCnt[SrcRoot] += CandyCnt[DestRoot];
	Root[DestRoot] = SrcRoot;
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
	{
		Root[i] = i;
		FriendCnt[i] = 1;
		cin >> CandyCnt[i];
	}

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;
		Union(Src, Dest);
	}

	for (int i = 1; i <= N; ++i)
	{
		int Root = Find(i);
		if (IsRoot[Root])
			continue;

		IsRoot[Root] = true;
		vecRoots.push_back(Root);
	}

	int Size = vecRoots.size();

	for (int i = 1; i <= Size; ++i)
	{
		int Root = vecRoots[i - 1];
		int PeopleCnt = FriendCnt[Root];

		for (int j = 0; j <= K; ++j)
		{
			if (j >= PeopleCnt)
			{
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - PeopleCnt] + CandyCnt[Root]);
			}

			else
			{
				DP[i][j] = DP[i - 1][j];
			}
			
		}
	}

	cout << DP[Size][K - 1];

}
