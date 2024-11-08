#include <iostream>
#include <vector>
#include <algorithm>

/*
BOJ 1263 시간 관리
풀이 방법 : 그리디 (정렬)
*/

using namespace std;

struct cmp
{
	bool operator() (const pair<int, int>& A, const pair<int, int>& B)
	{
		return A.second < B.second;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<pair<int, int>> vecWork(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecWork[i].first >> vecWork[i].second;
	}

	sort(vecWork.begin(), vecWork.end(), cmp());

	bool Enable = true;
	int StartTime = vecWork[0].second - vecWork[0].first;

	if (StartTime < 0)
	{
		cout << -1;
		return 0;
	}

	int CurTime = vecWork[0].second;

	for (int i = 1; i < N; ++i)
	{
		if (CurTime + vecWork[i].first <= vecWork[i].second)
		{
			CurTime += vecWork[i].first;
		}

		else
		{
			int PreTime = CurTime + vecWork[i].first - vecWork[i].second;
			CurTime = vecWork[i].second;
			StartTime -= PreTime;
		}

		if (StartTime < 0)
		{
			Enable = false;
			break;
		}
	}


	if (Enable)
		cout << StartTime;

	else
		cout << -1;
}
