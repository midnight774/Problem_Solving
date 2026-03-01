#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
BOJ 4386 별자리 만들기
풀이 방법 : MST

각 별들간의 거리계산로 간선 정보 생성 후 MST 구성
*/

int N;

int Root[101] = {};
struct Info
{
	int Src;
	int Dest;
	double Cost;
};

bool LessCost(const Info& lhs, const Info& rhs)
{
	return lhs.Cost < rhs.Cost;
}

int Find(int Num)
{
	if (Num == Root[Num])
		return Root[Num];

	Root[Num] = Find(Root[Num]);
	return Root[Num];
}

bool Union(int Src, int Dest)
{
	int SrcRoot = Find(Src);
	int DestRoot = Find(Dest);

	if (SrcRoot == DestRoot)
		return false;

	Root[SrcRoot] = DestRoot;
	return true;
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	vector<pair<double, double>> vecPos(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	for (int i = 0; i < N; ++i)
		Root[i] = i;

	vector<Info> vecInfo;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			Info Cur;
			Cur.Src = i;
			Cur.Dest = j;
			double XDist = (vecPos[i].first - vecPos[j].first);
			double YDist = (vecPos[i].second - vecPos[j].second);
			Cur.Cost = sqrt(XDist * XDist + YDist * YDist);

			vecInfo.push_back(Cur);
		}
	}

	sort(vecInfo.begin(), vecInfo.end(), LessCost);
	
	double Ans = 0.0;
	int Size = vecInfo.size();
	for (int i = 0; i < Size; ++i)
	{
		if (Union(vecInfo[i].Src, vecInfo[i].Dest))
		{
			Ans += vecInfo[i].Cost;
		}
	}

	cout << Ans;
}



