#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int K = 26;	//size of the alphabet

struct node {
	int f = 0;
	bool eow = false;
	node* child[K]; 

	node() { for (int i = 0; i < K; i++) { child[i] = NULL; }}
};

//To initialize, say Trie t; without ()
struct Trie {
	node* root;

	Trie() { root = new node(); }

	void addStr(string const& s) {
		node* cur = root;
		for (int i = 0; i < (int)s.size(); i++) {
			int idx = s[i] - 'a';
			if (cur->child[idx] == NULL) { cur->child[idx] = new node(); }
			cur = cur->child[idx];
		}
		cur->eow = true;
	}

	bool findWord(string const& word) {
		node* cur = root;
		for (int i = 0; i < (int)word.size(); i++) {
			int idx = word[i] - 'a';
			if (cur->child[idx] == NULL) { return false; }
			cur = cur->child[idx];
		}
		return cur->eow;	//return true if we want a prefix
	}

	void dfs(node* cur) {
		if (!cur) { return; }

		for (int i = 0; i < 26; i++) {
			if (cur->child[i]) {
				dfs(cur->child[i]);
				cur->f += cur->child[i]->f;
			}
		}

		if (cur->eow) { cur->f++; }
		if (cur->f >= 2 && cur != root) { cur->f -= 2; }
	}
};