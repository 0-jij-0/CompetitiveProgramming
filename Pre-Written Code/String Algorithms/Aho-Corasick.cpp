#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int K = 26;	//size of the alphabet

struct node {
	bool eow = false; int checked = -1;
	node *child[K], *p;
	node *link = NULL;	//points to the longest available proper suffix of the current prefix e.g. abc -> bc
	node *go[K];	// go[idx] returns child[idx] if available or link->child[idx] if available or link->link->child[idx]...
	char ch;

	node(node *p = NULL, char _ch = '$') : p(p), ch(_ch) {
		for (int i = 0; i < K; i++) { child[i] = go[i] = NULL; }
	}
};

//To initialize, say Trie t; without ()
struct Trie {
	node* root;

	Trie() { root = new node(); }

	void addStr(string const& s) {
		node* cur = root;
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'a';
			if (cur->child[idx] == NULL) { cur->child[idx] = new node(cur, s[i]); }
			cur = cur->child[idx];
		}
		cur->eow = true;
	}

	node* getLink(node *v) {
		if (v->link == NULL) {
			if (v == root || v->p == root) { v->link = root; }
			else { v->link = go(getLink(v->p), v->ch); }
		}
		return v->link;
	}

	//Finds the next state starting from v given input ch
	node* go(node *v, char ch) {
		int idx = ch - 'a';
		if (v->go[idx] == NULL) {
			if (v->child[idx]) { v->go[idx] = v->child[idx]; }
			else { v->go[idx] = v == root ? root : go(getLink(v), ch); }
		}
		return v->go[idx];
	}

	//Returns true if v represents a suffix of a word in the trie
	//Memoized
	bool check(node *v) {
		if (!v || v == root) { return 0; }
		if (v->checked != -1) { return v->checked; }
		if (v->eow) { return v->checked = 1; }

		return v->checked = check(getLink(v));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}