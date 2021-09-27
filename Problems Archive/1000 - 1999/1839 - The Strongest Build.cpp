#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

struct TrieNode {
	map<int, TrieNode*> nextNode;

	void insert(vector<int>& v) {
		TrieNode* cur = this; for (auto& x : v) {
			bool count = cur->nextNode.count(x);
			if (!count) { cur->nextNode[x] = new TrieNode(); }
			cur = cur->nextNode[x];
		}
	}

	bool count(vector<int>& v) {
		TrieNode* cur = this; for (auto& x : v) {
			bool count = cur->nextNode.count(x);
			if (!count) { return false; }
			cur = cur->nextNode[x];
		}
		return true;
	}
};

vector<vector<ll>> slots;

struct pqObj {
	vector<int> idx;

	pqObj(vector<int> _idx) : idx(_idx) {}

	bool operator < (const pqObj& rhs) const {
		int n = (int)idx.size(); ll lS = 0, rS = 0;
		for (int i = 0; i < n; i++) {
			lS += slots[i][idx[i]];
			rS += slots[i][rhs.idx[i]];
		}
		return lS < rS;
	}
};

priority_queue<pqObj> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; slots.resize(n);
	vector<int> cur; for (auto& x : slots) {
		int c; cin >> c; x.resize(c);
		for (auto& y : x) { cin >> y; }
		cur.push_back(c - 1);
	}

	TrieNode* banned = new TrieNode();
	int m; cin >> m; while (m--) {
		vector<int> v(n);
		for (auto& x : v) { cin >> x; x--; }
		banned->insert(v);
	}

	TrieNode* visited = new TrieNode();
	pq.push(pqObj(cur)); while (true) {
		cur = pq.top().idx; pq.pop();
		if (!banned->count(cur)) {
			for (auto& x : cur) cout << x + 1 << ' '; 
			cout << '\n'; break;
		}

		for (int i = 0; i < n; i++)	if (cur[i]) { 
			cur[i]--; if (visited->count(cur)) { cur[i]++; continue; }
			visited->insert(cur); pq.push(pqObj(cur)); cur[i]++;
		}
	}

	cin.ignore(2); return 0;
}