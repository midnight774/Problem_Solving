#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 3108 로고
풀이 방법 : 유니온파인드 + AABB충돌
*/

int N;
int Root[1002] = {};
bool Check[1002] = {};

struct Square
{
	int L;
	int B;
	int R;
	int T;
};

// inner가 outer 안에 완전히 들어가 있는지 체크
bool IsInside(const Square& inner, const Square& outer)
{
	return inner.L > outer.L &&
		inner.R < outer.R &&
		inner.B > outer.B &&
		inner.T < outer.T;
}

// 두 사각형이 교차하는지 판정
bool IsIntersect(const Square& a, const Square& b)
{
	// 완전히 포함되는 경우 교차 아님
	if (IsInside(a, b) || IsInside(b, a))
		return false;

	if (a.L > b.R || a.R < b.L || a.T < b.B || a.B > b.T)
		return false;

	return true;
}

int Find(int Num)
{
	if (Root[Num] == Num)
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

	/*
	꼭짓점 간의 이동
	꼭짓점 간 간선?

	교차되지 않는 사각형이 있는지 여부
	*/
	
	int N;
	cin >> N;
	int GroupCnt = N;

	vector<Square> vecSquare(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecSquare[i].L >> vecSquare[i].B
			>> vecSquare[i].R >> vecSquare[i].T;

		Root[i] = i;
	}
	
	Root[N] = N;

	vecSquare.push_back({ 0,0,0,0 });

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			if (i == j)
				continue;

			Square Src = vecSquare[i];
			Square Dest = vecSquare[j];

			if (Src.L > Dest.L)
			{
				Square Tmp = Src;
				Src = Dest;
				Dest = Tmp;
			}

			if (IsIntersect(Src, Dest))
			{
				Union(i, j);
			}
		}
	}

	bool Enable = false;
	int Ans = -1;

	for (int i = 0; i <= N; ++i)
	{
		int Root = Find(i);

		if (!Check[Root])
		{
			Check[Root] = true;
			++Ans;
		}
	}

	cout << Ans;
}

