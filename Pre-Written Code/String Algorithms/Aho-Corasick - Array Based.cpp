#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int K = 26;	//size of the alphabet

struct node {
	bool eow = false; int checked = -1;
	int child[K], p;
	int link = -1;	//points to the longest available proper suffix of the current prefix e.g. abc -> bc
	int go[K];	// go[idx] returns child[idx] if available or link->child[idx] if available or link->link->child[idx]...
	char ch;

	node(int _p = -1, char _ch = '$') : p(_p), ch(_ch) {
		for (int i = 0; i < K; i++) { child[i] = go[i] = -1; }
	}
};

//To initialize, say Trie t; without ()
struct Trie {
	int root;
	vector<node*> nodes;

	Trie() { nodes.push_back(new node()); root = 0; }

	void addStr(string const& s) {
		int cur = root;
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'A';
			if (nodes[cur]->child[idx] == -1) {
				nodes[cur]->child[idx] = nodes.size();
				nodes.push_back(new node(cur, s[i]));
			}
			cur = nodes[cur]->child[idx];
		}
		nodes[cur]->eow = true;
	}

	int getLink(int v) {
		node* vn = nodes[v];
		if (vn->link == -1) {
			if (v == root || vn->p == root) { vn->link = root; }
			else { vn->link = go(getLink(vn->p), vn->ch); }
		}
		return vn->link;
	}

	int go(int v, char ch) {
		int idx = ch - 'A';
		node* vn = nodes[v];
		if (vn->go[idx] == -1) {
			if (vn->child[idx] != -1) { vn->go[idx] = vn->child[idx]; }
			else { vn->go[idx] = v == root ? root : go(getLink(v), ch); }
		}
		return vn->go[idx];
	}

	//Returns true if v represents a suffix of a word in the trie
	//Memoized
	bool check(int v) {
		if (v == -1 || v == root) { return 0; }
		node* vn = nodes[v];
		if (vn->checked != -1) { return vn->checked; }
		if (vn->eow) { return vn->checked = 1; }

		return vn->checked = check(getLink(v));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}