#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct node {
	int priority, size, val;
	ll sum; bool reverse;
	node* l, * r; node() {}

	node(int v) : val(v), priority(rand()), l(NULL), r(NULL), size(1) {
		sum = val; reverse = 0;
	}

	void updateSize() {
		size = 1 + (l ? l->size : 0) + (r ? r->size : 0);
	}
	void combine() {
		sum = val + (l ? l->sum : 0) + (r ? r->sum : 0);
	}
};

int sz(node* t) { return t ? t->size : 0; }

void lazy(node* t) {
	if (!t) { return; }
	t->updateSize();
	if (t->reverse) {
		t->reverse = false;
		swap(t->l, t->r);
		if (t->l) { t->l->reverse ^= 1; }
		if (t->r) { t->r->reverse ^= 1; }
	}
}

void operation(node* t) {
	if (!t) { return; }
	lazy(t->l); lazy(t->r);
	t->combine();
}

void split(node* t, node*& l, node*& r, int pos, int add = 0) {
	if (!t) { l = r = NULL; return; }
	lazy(t); int curPos = add + sz(t->l);
	if (curPos < pos) { split(t->r, t->r, r, pos, curPos + 1); l = t; }
	else { split(t->l, l, t->l, pos, add); r = t; }
	if (t) { operation(t); }
}

void merge(node*& t, node* l, node* r) {
	lazy(l); lazy(r);
	if (!l || !r) { t = l ? l : r; }
	else if (l->priority > r->priority) { merge(l->r, l->r, r); t = l; }
	else { merge(r->l, l, r->l); t = r; }
	if (t) { operation(t); }
}

void insert(node*& root, node* x) {
	if (!root) { root = x; return; }
	merge(root, root, x);
}

void reverse(node*& t, int l, int r) {
	if (l > r) { return; }
	node* t1, * t2, * t3;
	split(t, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	if (t2) { t2->reverse ^= 1; operation(t2); }
	merge(t, t1, t2);
	merge(t, t, t3);
}

ll findSum(node*& t, int l, int r) {
	if (l > r) { return 0; }
	node* t1, * t2, * t3;
	split(t, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	operation(t2);
	ll res = t2 ? t2->sum : 0;
	merge(t, t1, t2);
	merge(t, t, t3);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	node* treap = nullptr;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		insert(treap, new node(x));
	}

	while (m--) {
		int t, l, r; cin >> t >> l >> r; t--;
		if (t) { cout << findSum(treap, l, r) << '\n'; }
		else { reverse(treap, l, r); }
	}
}