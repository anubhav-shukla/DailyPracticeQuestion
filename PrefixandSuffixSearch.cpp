
#include <bits/stdc++.h>
using namespace std;
struct Trie {
	Trie* arr[27] = { NULL };
	int idx;
};

Trie* root = new Trie();

void insert(string word, int i)
{
	Trie* temp = root;

	for (char ch : word) {

		if (temp->arr[ch - 'a'] == NULL) {
			Trie* t = new Trie();
			temp->arr[ch - 'a'] = t;
		}

		temp = temp->arr[ch - 'a'];
		temp->idx = i;
	}
}
int search(string word)
{
	Trie* temp = root;

	for (char ch : word) {

		if (temp->arr[ch - 'a'] == NULL)
			return -1;
		temp = temp->arr[ch - 'a'];
	}
	return temp->idx;
}

void findMatchingString(
	string words[], int n,
	vector<vector<string> > Q)
{
	string temp, t;

	for (int i = 0; i < n; i++) {
		temp = "{" + words[i];

		for (int j = words[i].size() - 1;
			j >= 0; j--) {
			t = words[i][j] + temp;
			temp = t;

			// Insert into Trie
			insert(t, i);
		}
	}

	for (int i = 0; i < Q.size(); i++) {

		string prefix = Q[i][0];
		string suffix = Q[i][1];
		string temp = suffix + "{" + prefix;

		int res;

		res = search(temp);

		if (res != -1) {
			cout << words[res] << '\n';
		}

		else
			cout << "-1\n";
	}
}

int main()
{
	string arr[]
		= { "apple", "app", "biscuit",
			"mouse", "orange", "bat",
			"microphone", "mine" };
	int N = 8;
	vector<vector<string> > Q = { { "a", "e" }, { "mi", "ne" } };
	findMatchingString(arr, N, Q);

	return 0;
}
