#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> res;

struct trieNode {
	vector<int> idx;
	map<string, trieNode*> child;
	trieNode() {}
};

void insertWord(trieNode *cur, string &s, int i) {
	stringstream ss(s); string w;
	while (ss >> w) {
		cur->idx.push_back(i);
		if (cur->child.count(w)) { cur = cur->child[w]; continue; }
		cur->child[w] = new trieNode(); cur = cur->child[w];
	}
	cur->idx.push_back(i);
}

void minWords(trieNode* cur, string &w) {
	if ((int)cur->idx.size() == 1) { res[cur->idx.front()] = w; return; }
	for (auto& x : cur->child) {
		w =(w.empty() ? x.first : w + " " + x.first);
		minWords(x.second, w);
		auto it = find(w.rbegin(), w.rend(), ' ');
		if (it == w.rend()) { w = ""; continue; }
		int idx = (int)w.size() - 1 - (it - w.rbegin());
		w.erase(w.begin() + idx, w.end());
	}
}

int main() {
	freopen("list.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string N; getline(cin, N); string s;
	int n = stoi(N); res.resize(n);
	trieNode* root = new trieNode();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		insertWord(root, s, i);
	}
	if (n == 1) {
		int idx = find(s.begin(), s.end(), ' ') - s.begin();
		s.erase(s.begin() + idx, s.end());
		cout << s << '\n';
	}
	else {
		string w = ""; minWords(root, w);
		for (auto& x : res) cout << x << '\n';
	}
	cin.ignore(2); return 0;
}