#include <bits/stdc++.h>
using namespace std;
const int K = 26;
const char first = 'a';

vector<string> v;

struct TrieNode {
	int nextNode[K]; int wordCount = 0;

	TrieNode() {
		fill(nextNode, nextNode + K, -1);
	}
};

struct Trie {
	const int root = 0;
	vector<TrieNode> nodes;

	Trie() { nodes.emplace_back(); }

	void addString(const string& s) {
		int cur = root;
		for (const char& c : s) {
			nodes[cur].wordCount++;
			if (nodes[cur].nextNode[c - first] == -1) {
				nodes[cur].nextNode[c - first] = (int)nodes.size();
				nodes.emplace_back();
			}
			cur = nodes[cur].nextNode[c - first];
		}
		nodes[cur].wordCount++;
	}
	
	int LCP(const string& s) {
		int len = 0; int cur = root;
		for (const char c : s) {
			if (nodes[cur].wordCount < 2) return len - 1; ++len;
			cur = nodes[cur].nextNode[c - first];
		}
		return (int)s.size() - (nodes[cur].wordCount < 2);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; Trie T = Trie(); v.resize(n);
	for (auto& x : v) { cin >> x; T.addString(x); }
	for (int i = 0; i < n; i++) 
		cout << T.LCP(v[i]) << '\n';

}