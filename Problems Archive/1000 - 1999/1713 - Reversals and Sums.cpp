#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct node {
	int priority, size, val;
	ll sum, prefVal, sufVal, maxRange;
	bool pref0, suf0;
	bool reverse;
	node* l, * r;

	node() {}
	node(int v) :val(v), priority(rand()), l(NULL), r(NULL), size(1) {
		sum = prefVal = sufVal = val;
		pref0 = suf0 = val == 0;
		maxRange = 1;
		reverse = 0;
	}

	void updateSize() {
		size = 1 + (l ? l->size : 0) + (r ? r->size : 0);
	}
	void combine() {
		sum = val + (l ? l->sum : 0) + (r ? r->sum : 0);

		if (l) {
			prefVal = l->prefVal; pref0 = l->pref0;
			if (prefVal == l->size && val == !l->pref0) {
				prefVal++;
				if (r && val == !r->pref0) { prefVal += r->prefVal; }
			}
		}
		else {
			prefVal = 1; pref0 = !(bool)val;
			if (r && val == !r->pref0) { prefVal += r->prefVal; }
		}

		if (r) {
			sufVal = r->sufVal; suf0 = r->suf0;
			if (sufVal == r->size && val == !r->suf0) {
				sufVal++;
				if (l && val == !l->suf0) { sufVal += l->sufVal; }
			}
		}
		else {
			sufVal = 1; suf0 = !(bool)val;
			if (l && val == !l->suf0) { sufVal += l->sufVal; }
		}

		ll midVal = 1;
		if (l && val == !l->suf0) { midVal += l->sufVal; }
		if (r && val == !r->pref0) { midVal += r->prefVal; }

		maxRange = midVal;
		if (l) { maxRange = max(maxRange, l->maxRange); }
		if (r) { maxRange = max(maxRange, r->maxRange); }
		maxRange = max({ maxRange, prefVal, sufVal });
	}
};

int sz(node* t) { return t ? t->size : 0; }

void lazy(node* t) {
	if (!t) { return; }
	t->updateSize();
	if (t->reverse) {
		t->reverse = false;
		swap(t->prefVal, t->sufVal);
		swap(t->pref0, t->suf0);
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

//Splits the subtree rooted at t into two trees according pos (pos is in the left subtree)
//It will set l as the root of the l subtree and r as the root of the r subtree
//pos 1-indexed
void split(node* t, node*& l, node*& r, int pos, int add = 0) {
	if (!t) { l = r = NULL; return; }
	lazy(t); int curPos = add + sz(t->l);
	if (curPos < pos) { split(t->r, t->r, r, pos, curPos + 1); l = t; }
	else { split(t->l, l, t->l, pos, add); r = t; }
	if (t) { operation(t); }
}

//merges two treaps l and r and stores the root in t
//assumes nodes in l have < vals than nodes in r
void merge(node*& t, node* l, node* r) {
	lazy(l); lazy(r);
	if (!l || !r) { t = l ? l : r; }
	else if (l->priority > r->priority) { merge(l->r, l->r, r); t = l; }
	else { merge(r->l, l, r->l); t = r; }
	if (t) { operation(t); }
}

//Inserts x at the end of the array represented by root
void insert(node*& root, node* x) {
	if (!root) { root = x; return; }
	merge(root, root, x);
}

//Reverses subarray [l,r] (1-indexed) in the array represented by t
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

//Prints the array represented by cur
void print(node* cur) {
	if (!cur) { return; }
	lazy(cur);
	print(cur->l);
	cout << cur->val;
	print(cur->r);
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

	cin.ignore(2); return 0;
}