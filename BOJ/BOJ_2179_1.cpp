#include <iostream>
#include <vector>
#include <unordered_set>

/*
BOJ 2179 비슷한 단어
풀이 방법 : 트라이
 */

using namespace std;

const int Max = 27;
int MaxLength = 0;
unordered_set<string> setPre = {};

int GetIndex(char ch)
{
	return (int)(ch - 'a');
}

struct Trie
{
	Trie* Node[Max] = {};

	Trie()
	{
	}

	~Trie()
	{
		for (int i = 0; i < Max; ++i)
		{
			if (Node[i])
				delete Node[i];
		}
	}

	void Insert(const string& key, int Index = 0)
	{
		if (Index == key.length())
			return;

		int Next = GetIndex(key[Index]);

		if (Node[Next] == nullptr)
			Node[Next] = new Trie;

		else
		{
			if (MaxLength <= Index + 1)
			{
				setPre.insert(key.substr(0, Index + 1));
				MaxLength = Index + 1;
			}
		}

		Node[Next]->Insert(key, Index + 1);
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	Trie t;

	vector<string> vecString(N);
	unordered_set<string> setCheck;

	for (int i = 0; i < N; ++i)
	{
		cin >> vecString[i];

		if(setCheck.find(vecString[i]) == setCheck.end())
		{
			setCheck.insert(vecString[i]);
			t.Insert(vecString[i], 0);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		string Pre = vecString[i].substr(0, MaxLength);
		bool Enable = false;
		
		if (setPre.find(Pre) != setPre.end())
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (vecString[i] != vecString[j]
					&& vecString[j].substr(0, MaxLength) == Pre)
				{
					cout << vecString[i] << '\n';
					cout << vecString[j] << '\n';
					Enable = true;
					break;
				}
			}
		}

		if (Enable)
			break;
	}

}

