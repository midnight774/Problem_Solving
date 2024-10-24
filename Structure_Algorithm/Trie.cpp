  #include <iostream>

using namespace std;

const int Max = 10;

int GetIndex(char ch)
{
	return ch - '0';
}

struct Trie
{
	bool IsFin;
	Trie* Node[Max] = {};

	Trie()
	{
		IsFin = false;
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
			IsFin = true;

		else
		{
			int Next = GetIndex(key[Index]);

			if (Node[Next] == nullptr)
				Node[Next] = new Trie;

			Node[Next]->Insert(key, Index + 1);
		}
	}

	bool Find(const string& key, int Depth = 0)
	{
		if (Depth == key.length() && IsFin)
			return true;

		else
		{
			int Next = GetIndex(key[Depth]);

			if (Node[Next] == nullptr)
				return false;

			else
				return Node[Next]->Find(key, Depth + 1);
		}
	}

	bool Find2(const string& key, int Depth = 0)
	{
		if (Depth >= key.length())
			return false;

		if (Depth != key.length() && IsFin)
		{
			return true;
		}

		else
		{
			int Next = GetIndex(key[Depth]);

			if (Node[Next] == nullptr)
				return false;

			else
				return Node[Next]->Find2(key, Depth + 1);
		}
	}
};
