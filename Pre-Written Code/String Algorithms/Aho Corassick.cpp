#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int K = 26;
const char first = 'a';
const char dontCare = '$';

struct TrieNode {
	int nextNode[K];
	bool word = false;
	int par = -1; char parChar = dontCare;
	int suffixLink = -1;
	int dfaLinks[K];

	TrieNode(char c = dontCare, int p = -1) : par(p), parChar(c) {
		fill(nextNode, nextNode + K, -1);
		fill(dfaLinks, dfaLinks + K, -1);
	}
};

struct Trie {
	const int root = 0;
	vector<TrieNode> nodes;

	Trie() { nodes.emplace_back(); }

	void addString(const string& s) {
		int cur = root;
		for (const char& c : s) {
			if (nodes[cur].nextNode[c - first] == -1) {
				nodes[cur].nextNode[c - first] = (int)nodes.size();
				nodes.emplace_back(c, cur);
			}
			cur = nodes[cur].nextNode[c - first];
		}
		nodes[cur].word = true;
	}

	int getSuffixLink(int i) {
		int& A = nodes[i].suffixLink; if (A != -1) return A;
		if (i == root || nodes[i].par == root) { return A = root; }
		return A = dfaMove(getSuffixLink(nodes[i].par), nodes[i].parChar);
	}

	int dfaMove(int i, char c) {
		int x = c - first, &A = nodes[i].dfaLinks[x];
		if (A != -1) return A;
		if (nodes[i].nextNode[x] != -1) return A = nodes[i].nextNode[x];
		return A = (i == root) ? root : dfaMove(getSuffixLink(i), c);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin.ignore(2); return 0;
}