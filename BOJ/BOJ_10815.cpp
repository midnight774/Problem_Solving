#include <iostream>
#include <vector>
#include <algorithm>

/* 
BOJ 10815 숫자 카드 2
풀이 방법 : 이진 탐색
*/

//lower_bound : 타겟 넘버가 어디에서 가장 처음으로 등장하는 인덱스 반환
//upper_bound : 타겟 넘버를 초과하는 숫자가 가장 처음으로 등장하는 인덱스 반환

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecCard(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecCard[i];
	}

	sort(vecCard.begin(), vecCard.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int Num;
		cin >> Num;

		auto Lower_Iter = lower_bound(vecCard.begin(), vecCard.end(), Num);
		auto Upper_Iter = upper_bound(vecCard.begin(), vecCard.end(), Num);

		cout << Upper_Iter - Lower_Iter << ' ';
	}
}
