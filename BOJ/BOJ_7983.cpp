#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 7983번 내일 할거야
풀이 방법 : 정렬
*/

struct Info
{
	int Day;
	int FinDate;
};

bool Cmp(const Info& Src, const Info& Dest)
{
	if (Src.FinDate == Dest.FinDate)
		return Src.FinDate > Dest.FinDate;

	return Src.FinDate > Dest.FinDate;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Info> vecInfo(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecInfo[i].Day >> vecInfo[i].FinDate;
	}

	sort(vecInfo.begin(), vecInfo.end(), Cmp);

	int CurDate = vecInfo[0].FinDate - vecInfo[0].Day;
	for (int i = 1; i < N; ++i)
	{
		if (vecInfo[i].FinDate < CurDate)
		{
			CurDate = vecInfo[i].FinDate;
		}

		CurDate -= vecInfo[i].Day;
	}

	cout << CurDate;
}

