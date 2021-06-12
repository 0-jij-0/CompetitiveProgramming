#include <iostream>
#include <string>
#include <array>
using namespace std;

struct TrieNode {
	int word = 0, d = 0;
	array<TrieNode*, 26> nextNode;

	TrieNode(int _d) : d(_d) { nextNode.fill(nullptr); }
};

void insertWord(string& s, TrieNode *root) {
	TrieNode* cur = root; int d = 1;
	for (char& c : s) {
		if (cur->nextNode[c - 'a'] == nullptr)
			cur->nextNode[c - 'a'] = new TrieNode(d);
		cur = cur->nextNode[c - 'a']; d++;
	}
	cur->word++;
}

void dfs(TrieNode* cur, int& res) {
	if (cur == nullptr) { return; }
	if (cur->d & 1) { res ^= cur->word; }
	for (int i = 0; i < 26; i++)
		dfs(cur->nextNode[i], res);
}

int main() {
	freopen("game.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		TrieNode* root = new TrieNode(0);
		int n; cin >> n; while (n--) {
			string s; cin >> s; insertWord(s, root);
		}
		int res = 0; dfs(root, res);
		cout << (res ? "Pillow" : "Khaled") << '\n';
	}
	cin.ignore(2); return 0;
}