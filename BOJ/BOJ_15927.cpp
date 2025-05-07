#include <iostream>

using namespace std;

/*
BOJ 15927번 회문은 회문이 아냐
풀이 방법 : 애드 혹

문자열이 싹 다 동일한 알파벳으로 이뤄진 경우를 제외 하면
팰린드롬 문자열에서 앞 또는 뒤를 빼면 해당 부분 문자열은 팰린드롬이 아니다.
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string Input;
	cin >> Input;

	int Length = Input.length();
	int Mid = Length / 2;

	bool IsPalindrome = true;
	for (int i = 0; i < Mid; ++i)
	{
		if (Input[i] != Input[Length - i - 1])
		{
			IsPalindrome = false;
			break;
		}
	}

	if (!IsPalindrome)
	{
		cout << Length;
		return 0;
	}

	--Length;
	Mid = Length / 2;

	for (int i = 0; i < Mid; ++i)
	{
		if (Input[i] != Input[Length - i - 1])
		{
			IsPalindrome = false;
			break;
		}
	}

	if (!IsPalindrome)
	{
		cout << Length;
	}

	else
	{
		cout << -1;
	}

}


