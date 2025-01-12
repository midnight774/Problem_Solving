#include <iostream>

/*
BOJ 13909 창문 닫기
풀이 방법 : 수학, 정수론

약수의 개수가 홀수개라면 제곱수
=>일반적으로 약수는 짝을 이루기 때문
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		int Num = i * i;
		if (Num > N)
			break;

		++Cnt;
	}
	
	cout << Cnt;
}
