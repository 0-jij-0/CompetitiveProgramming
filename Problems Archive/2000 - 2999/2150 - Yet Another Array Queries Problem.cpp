#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct node {
	int priority, size; int val;
	bool reverse; node* l, * r; node() {}
	node(int v) :val(v), priority(rand()), l(NULL), r(NULL), size(1), reverse(0) {}

	void updateSize() { size = 1 + (l ? l->size : 0) + (r ? r->size : 0); }
};

int sz(node* t) { return t ? t->size : 0; }

void lazy(node* t) {
	if (!t || !t->reverse) { return; }
	t->reverse = false;
	swap(t->l, t->r);
	if (t->l) { t->l->reverse ^= 1; }
	if (t->r) { t->r->reverse ^= 1; }
}

void split(node* t, node*& l, node*& r, int pos, int add = 0) {
	if (!t) { l = r = NULL; return; }
	lazy(t); int curPos = add + sz(t->l);
	if (curPos < pos) { split(t->r, t->r, r, pos, curPos + 1); l = t; }
	else { split(t->l, l, t->l, pos, add); r = t; }
	if (t) { t->updateSize(); }
}

void merge(node*& t, node* l, node* r) {
	lazy(l); lazy(r);
	if (!l || !r) { t = l ? l : r; }
	else if (l->priority > r->priority) { merge(l->r, l->r, r); t = l; }
	else { merge(r->l, l, r->l); t = r; }
	if (t) { t->updateSize(); }
}

void insert(node*& root, node* x) {
	if (!root) { root = x; return; }
	merge(root, root, x);
}

void reverse(node*& t, int l, int r) {
	if (l > r) { return; }
	node* t1, * t2, * t3;
	split(t, t2, t3, r + 1);
	split(t2, t1, t2, l);
	if (t2) { t2->reverse ^= 1; }
	merge(t, t1, t2);
	merge(t, t, t3);
}

void rotate(node*& t, int l, int r) {
	if (l > r) { return; }
	node* t1, * t2, * t3, * t4;
	split(t, t3, t4, r + 1);
	split(t3, t2, t3, r);
	split(t2, t1, t2, l);

	merge(t, t1, t3);
	merge(t, t, t2);
	merge(t, t, t4);
}

void getFinalArray(node* cur, vector<int>& res) {
	if (!cur) { return; }
	lazy(cur);
	getFinalArray(cur->l, res);
	res.push_back(cur->val);
	getFinalArray(cur->r, res);
}

void print(node* cur) {
	if (!cur) { return; }
	lazy(cur);
	print(cur->l);
	cout << cur->val << ' ';
	print(cur->r);
}

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q, m; cin >> n >> q >> m;

	node* treap = nullptr; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		insert(treap, new node(x));
	}

	while (q--) {
		int t, l, r; cin >> t >> l >> r; --t; --l; --r;
		t ? reverse(treap, l, r) : rotate(treap, l, r);
	}

	getFinalArray(treap, A);
	while (m--) { int i; cin >> i; cout << A[--i] << ' '; }
	cout << '\n';
}