#include <iostream>
#include <queue>
#include <algorithm>

/*
BOJ 12764 싸지방에 간 준하
풀이 방법 : 우선 순위 큐
강의실 배정 문제 풀이 방법 + 빈 자리 정보를 가진 우선 순위 큐 이용
 */

using namespace std;

int Cnt[100001] = {};

struct Info
{
	int End;
	int Seat = -1;
};

struct cmp
{
	bool operator() (const Info& A, const Info& B)
	{
		return A.End > B.End;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int >> vecPair(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecPair[i].first >> vecPair[i].second;
	}

	sort(vecPair.begin(), vecPair.end());

	priority_queue<Info, vector<Info>, cmp> pqInfo;
	priority_queue<int, vector<int>, greater<>> pqSeat;
	int MaxSeat = 0;

	for (int i = 0; i < N; ++i)
	{
		bool IsPushed = false;

		Info Next;
		Next.End = vecPair[i].second;

		while (!pqInfo.empty())
		{
			Info Cur = pqInfo.top();

			if (Cur.End < vecPair[i].first)
			{
				pqInfo.pop();
				IsPushed = true;
				pqSeat.push(Cur.Seat);
			}

			else
				break;
		}

		if (pqSeat.empty())
		{
			Next.Seat = pqInfo.size() + 1;
			MaxSeat = max(MaxSeat, Next.Seat);
			pqInfo.push(Next);
		}

		else
		{
			Next.Seat = pqSeat.top();
			++Cnt[Next.Seat];
			pqSeat.pop();
			pqInfo.push(Next);
		}
	}

	while (!pqInfo.empty())
	{
		++Cnt[pqInfo.top().Seat];
		pqInfo.pop();
	}

	while (!pqSeat.empty())
	{
		++Cnt[pqSeat.top()];
		pqSeat.pop();
	}

	cout << MaxSeat << '\n';
	for (int i = 1; i <= MaxSeat; ++i)
		cout << Cnt[i] << ' ';

}
