#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 13305 주유소
풀이 방법 : 우선순위 큐
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	vector<int> vecRoad(N - 1);
	vector<int> vecPrice(N);
	for (int i = 0; i < N - 1; ++i)
		cin >> vecRoad[i];

	for (int i = 0; i < N; ++i)
		cin >> vecPrice[i];

	priority_queue<long long, vector<long long>, greater<>> pqPrice;

	long long Sum = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		pqPrice.push(vecPrice[i]);

		long long Price = pqPrice.top();

		Sum += Price * vecRoad[i];
	}

	cout << Sum;
}

