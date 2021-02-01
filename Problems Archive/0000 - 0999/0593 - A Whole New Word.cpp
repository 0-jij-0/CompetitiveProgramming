#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> p;

struct node {
	int c = 0; node * next[26];
	node() {
		for (int i = 0; i < 26; i++) { next[i] = NULL; }
	}
};

void add(node *trie, const string &s, const int &l) {
	node *cur = trie;
	for (int i = 0; i < l; i++) {
		if (cur->next[s[i] - 'A'] != NULL) {
			cur = cur->next[s[i] - 'A']; continue;
		}
		cur->c++; cur = cur->next[s[i] - 'A'] = new node();
	}
}

bool dfs(node *cur, string &res, const int &l) {
	if ((int)res.size() == l) { return false; }
	int s = (int)res.size();
	if (cur->c < (int)p[s].size()) {
		for (int i = 0; i < 26; i++) {
			if (!p[s].count(i + 'A')) { continue; }
			if (cur->next[i] != NULL) { continue; }
			res.push_back(i + 'A');
			for (int j = s + 1; j < l; j++) {
				res.push_back(*p[j].begin());
			}
			return true;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cur->next[i] == NULL) { continue; }
		res.push_back(i + 'A');
		bool b = dfs(cur->next[i], res, l);
		if (b) { return true; }
		res.pop_back();
	}
	return false;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int n, l; cin >> n >> l; p.clear();
		node * trie = new node(); p.resize(l);
		for (int i = 0; i < n; i++) {
			string s; cin >> s; add(trie, s, l);
			for (int j = 0; j < l; j++)
				p[j].insert(s[j]);	
		}
		string res = "";
		cout << "Case #" << t << ": ";
		cout << (dfs(trie, res, l) ? res : "-") << endl;
	}
	cin.ignore(2); return 0;
}