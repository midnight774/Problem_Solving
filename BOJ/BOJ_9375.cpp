#include <iostream>
#include <string>
#include <unordered_map>

/*
BOJ 9375 패션왕 신혜빈
풀이 방법 : 조합, 해시 테이블
각 카테고리에 속한 옷의 개수 + 1(해당 카테고리 안 입는 경우)
를 누적하여 곱해준 뒤
마지막에 싹 다 안 입는 경우 한 가지를 빼준다.
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T > 0)
	{
		--T;

		int N;
		cin >> N;

		unordered_map<string, int> mapCheck;
		cin.ignore(20, '\n');
		for (int i = 0; i < N; ++i)
		{
			string Input;
			getline(cin, Input);

			int Length = Input.length();
			for (int j = 0; j < Length; ++j)
			{
				if (Input[j] == ' ')
				{
					string Category = Input.substr(j + 1, Length - j - 1);
					++mapCheck[Category];
					break;
				}
			}
		}

		auto iter = mapCheck.begin();
		auto iterEnd = mapCheck.end();

		int Answer = 1;
		for (; iter != iterEnd; ++iter)
		{
			Answer *= (iter->second + 1);
		}

		Answer -= 1;
		cout << Answer << '\n';
	}
}
