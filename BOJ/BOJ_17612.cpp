#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 17612 쇼핑몰
풀이 방법 : 우선순위 큐
*/

struct Info
{
	long long Id;
	long long Cnt;
};

struct OutInfo
{
	long long Id;
	long long OutTime;
	long long SeatNum;
};

struct cmp
{
	bool operator() (const OutInfo& Src, const OutInfo& Dest)
	{
		if (Src.OutTime == Dest.OutTime)
			return Src.SeatNum < Dest.SeatNum;

		return Src.OutTime > Dest.OutTime;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	long long Ans = 0;

	priority_queue<long long, vector<long long>, greater<>> pqSeat;
	priority_queue<OutInfo, vector<OutInfo>, cmp> pqOut;

	vector<Info> vecInfo(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecInfo[i].Id >> vecInfo[i].Cnt;
	}

	long long CurTime = 0;
	long long Order = 1;
	for (int i = 0; i < N; ++i)
	{
		if (i < K)
		{
			pqOut.push({ vecInfo[i].Id, vecInfo[i].Cnt + CurTime, (long long)i });
		}

		else
		{
			if (pqOut.size() == K)
			{
				OutInfo Cur = pqOut.top();
				pqOut.pop();
				CurTime = Cur.OutTime;
				pqSeat.push(Cur.SeatNum);

				Ans += Order * (long long)Cur.Id;
				++Order;

				while (!pqOut.empty())
				{
					OutInfo Cur = pqOut.top();

					if (Cur.OutTime != CurTime)
						break;

					pqOut.pop();
					CurTime = Cur.OutTime;
					pqSeat.push(Cur.SeatNum);

					Ans += Order * (long long)Cur.Id;
					++Order;
				}
			}

			long long Seat = pqSeat.top();
			pqSeat.pop();
			pqOut.push({ vecInfo[i].Id, vecInfo[i].Cnt + CurTime, Seat });
		}


	}

	while (!pqOut.empty())
	{
		OutInfo Cur = pqOut.top();
		pqOut.pop();

		Ans += Order * (long long)Cur.Id;
		++Order;
	}
	
	cout << Ans;
}

