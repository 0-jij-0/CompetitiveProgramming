#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	node * rock;
	node * paper;
	node * scisors;
	bool full;

	node() :
		rock(NULL), paper(NULL), scisors(NULL), full(false) {}
};

void prepare_string(string &s, int size) {
	while (s.size() <= size/2) { s += s; }
	if (s.size() == size) { return; }
	int m = size - s.size();
	s = s + s.substr(0, m);
}

void insert(node * n, string s, int i) {
	if (n->full || i == s.size()) { return; }
	if (s[i] == 'R') {
		if (n->rock == NULL) {
			n->rock = new node();
			if (n->paper != NULL && n->scisors != NULL) { n->full = true; return; }
		}
		return insert(n->rock, s, i + 1);
	}
	if (s[i] == 'P') {
		if (n->paper == NULL) {
			n->paper = new node();
			if (n->rock != NULL && n->scisors != NULL) { n->full = true; return; }
		}
		return insert(n->paper, s, i + 1);
	}
	if (s[i] == 'S') {
		if (n->scisors == NULL) {
			n->scisors = new node();
			if (n->paper != NULL && n->rock != NULL) { n->full = true; return; }
		}
		return insert(n->scisors, s, i + 1);
	}
}

string my_program;

bool strategy(node * n) {
	if (n->full) { return false; }
	if (n->rock == NULL && n->paper == NULL && n->scisors == NULL) { return false; }
	if (n->rock == NULL && n->paper == NULL) { my_program.push_back('R'); return true; }
	if (n->rock == NULL && n->scisors == NULL) { my_program.push_back('S'); return true; }
	if (n->scisors == NULL && n->paper == NULL) { my_program.push_back('P'); return true; }
	if (n->rock == NULL) { my_program.push_back('S'); return strategy(n->scisors); }
	if (n->paper == NULL) { my_program.push_back('R'); return strategy(n->rock); }
	if (n->scisors == NULL) { my_program.push_back('P'); return strategy(n->paper); }
	while (true) {}
	return false;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		bool r = false, p = false, s = false;
		int n; cin >> n;
		my_program.clear();
		node * root = new node();
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			prepare_string(s, 500);
			insert(root, s, 0);
		}
		cout << "Case #" << i + 1 << ": ";
		if (!strategy(root)) { cout << "IMPOSSIBLE" << endl; }
		else { cout << my_program << endl; }
	}
	cin.ignore(2); return 0;
}