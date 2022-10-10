#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	int priority, size; char val; node* l, * r; node() {}
	node(char v) : val(v), priority(rand()), l(NULL), r(NULL), size(1) {}
	void updateSize() {
		size = 1 + (l ? l->size : 0) + (r ? r->size : 0);
	}
};

int sz(node* t) { return t ? t->size : 0; }


void split(node* t, node*& l, node*& r, int pos, int add = 0) {
	if (!t) { l = r = NULL; return; }
	int curPos = add + sz(t->l);
	if (curPos < pos) { split(t->r, t->r, r, pos, curPos + 1); l = t; }
	else { split(t->l, l, t->l, pos, add); r = t; }
	if (t) { t->updateSize(); }
}

void merge(node*& t, node* l, node* r) {
	if (!l || !r) { t = l ? l : r; }
	else if (l->priority > r->priority) { merge(l->r, l->r, r); t = l; }
	else { merge(r->l, l, r->l); t = r; }
	if (t) { t->updateSize(); }
}

void insert(node*& root, node* x) {
	if (!root) { root = x; return; }
	merge(root, root, x);
}

void print(node* cur) {
	if (!cur) { return; }
	print(cur->l);
	cout << cur->val;
	print(cur->r);
}

void cutPaste(int l, int r, node*& root) {
	node* L, *R;
	split(root, root, R, r);
	split(root, L, root, l - 1);
	merge(L, L, R);
	merge(root, L, root);
}

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q >> s;
	node* treap = nullptr; for (char &c : s) 
		insert(treap, new node(c));

	while (q--) {
		int l, r; cin >> l >> r;
		cutPaste(l, r, treap);
	}

	print(treap); cout << '\n';
}