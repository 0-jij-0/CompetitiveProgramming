#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct TrieNode {
	bool word = false;
	array<TrieNode*, 26> nextNode;
	TrieNode() { nextNode.fill(nullptr); }
};

void insertWord(TrieNode* root, const string& word) {
	TrieNode* cur = root;
	for (const char& c : word) {
		if (cur->nextNode[c - 'a'] == nullptr)
			cur->nextNode[c - 'a'] = new TrieNode();
		cur = cur->nextNode[c - 'a'];
	}
	cur->word = true;
}

ll dp[5001]; string s;

int main() {
	TrieNode* root = new TrieNode();
	cin >> s; int n = (int)s.size();
	int k; cin >> k; while (k--) {
		string t; cin >> t;
		insertWord(root, t);
	}

	dp[n] = 1; for (int i = n - 1; i >= 0; i--) {
		TrieNode* cur = root; dp[i] = 0;
		for (int j = i; j < n; j++) {
			if (cur->nextNode[s[j] - 'a'] == nullptr) { break; }
			cur = cur->nextNode[s[j] - 'a'];
			if (cur->word) dp[i] = (dp[i] + dp[j + 1]) % mod;
		}
	}

	cout << dp[0] << '\n'; delete root;
}