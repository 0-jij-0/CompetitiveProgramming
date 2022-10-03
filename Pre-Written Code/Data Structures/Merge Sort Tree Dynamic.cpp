//Implementation of a merge sort tree with update
//O(nlog^2n) time to preprocess with O(nlogn) space
//O(log^2n) time per query

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma region treap
struct node {
	int val, priority, size, freq;	//size accounts for duplicates here
	node *l = NULL, *r = NULL;

	node() {}
	node(int v) :val(v), priority(rand()), l(NULL), r(NULL), size(1), freq(1) {}

	void updateSize() {
		size = freq + (l ? l->size : 0) + (r ? r->size : 0);
	}
};

int sz(node* t) { return t ? t->size : 0; }

//Splits the subtree rooted at t into two trees according to curval (l <= and r >)
//It will set l as the root of the l subtree and r as the root of the r subtree
void split(node *t, node *&l, node *&r, int curVal) {
	if (!t) { l = r = NULL; }
	else if (t->val <= curVal) { split(t->r, t->r, r, curVal); l = t; }
	else { split(t->l, l, t->l, curVal); r = t; }
	if (t) t->updateSize();
}

//merges two treaps l and r and stores the root in t
//assumes nodes in l have < vals than nodes in r
void merge(node *&t, node *l, node *r) {
	if (!l || !r) { t = l ? l : r; }
	else if (l->priority > r->priority) { merge(l->r, l->r, r); t = l; }
	else { merge(r->l, l, r->l); t = r; }
	if (t) t->updateSize();
}

//Use as a check in case of duplicates
bool find(node *cur, int key, int add = 0) {
	if (!cur) { return false; }
	if (cur->val == key) { cur->freq += add; cur->updateSize(); return cur->freq > 0; }
	bool b = find(cur->val < key ? cur->r : cur->l, key, add);
	if (b && add) cur->updateSize();
	return b;
}

//Inserts u into the treap rooted at t
void insertR(node *&t, node *u) {
	if (!t) { t = u; }
	else if (u->priority > t->priority) { split(t, u->l, u->r, u->val); t = u; }
	else { insertR(t->val <= u->val ? t->r : t->l, u); }
	if (t) t->updateSize();
}
//Call this one; deals with duplicates
void insert(node *&t, node *u) { if (!find(t, u->val, 1)) { insertR(t, u); } }

//Erases the node with val k in the subtree of t
void erase(node *&t, int key) {
	if (!t) { return; }
	if (!find(t, key, -1)) {
		if (t->val == key) { node* tmp = t; merge(t, t->l, t->r); delete tmp; }
		else { erase(t->val < key ? t->r : t->l, key); }
		if (t) t->updateSize();
	}
}

//Find kth smallest nodes (counting duplicates)
int findKth(node *cur, int k) {
	if (sz(cur->l) >= k) { return findKth(cur->l, k); }
	if (sz(cur->l) <= k - 1 && sz(cur->l) >= k - cur->freq) { return cur->val; }
	return findKth(cur->r, k - sz(cur->l) - cur->freq);
}

//Find number of elements <= key
int count(node *cur, int key) {
	if (!cur) { return 0; }
	if (cur->val > key) { return count(cur->l, key); }
	else { return sz(cur->l) + cur->freq + count(cur->r, key); }
}

void dfs(node *cur, vector<int> &res) {
	if (!cur) { return; }
	dfs(cur->l, res);
	for (int i = 0; i < cur->freq; i++) { res.push_back(cur->val); }
	dfs(cur->r, res);
}

vector<int> getAllValues(node *root) {
	vector<int> res;
	dfs(root, res);
	return move(res);
}
#pragma endregion

struct StVal {
	node *treap = NULL;
	int v = 0; StVal() {}
	StVal(const int _v) : v(_v) { treap = new node(v); }
	StVal(const StVal &v1, const StVal &v2) {
		treap = NULL;
		vector<int> el1 = getAllValues(v1.treap);
		vector<int> el2 = getAllValues(v2.treap);
		for (int el : el1) { insert(treap, new node(el)); }
		for (int el : el2) { insert(treap, new node(el)); }
	}
	operator int() const { return v; }
};

struct SegTree {
	int n;
	vector<int> leaves;
	vector<StVal> st;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}

	//lo, hi indices of the actual array; si is the index of the segment tree array
	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) { st.resize(si + 1); }
			st[si] = StVal();			//Set the actual array here
			leaves[lo] = si;
			return;
		}
		int lC = si << 1, rC = (si << 1) | 1, mid = (lo + hi) >> 1;
		init(lC, lo, mid); init(rC, mid + 1, hi);
		st[si] = StVal(st[lC], st[rC]);
	}

	int getSmaller(int l, int r, int k) { return getSmaller(l, r, k, 1, 0, n - 1); }
	int getSmaller(int l, int r, int k, int si, int lo, int hi) {		//returns number of elements < k in [l..r]
		if (lo > r || hi < l) { return 0; }
		if (l <= lo && hi <= r) {
			return count(st[si].treap, k - 1);
		}

		int mid = (lo + hi) >> 1;
		if (r <= mid) return getSmaller(l, r, k, si << 1, lo, mid);
		if (mid < l) return getSmaller(l, r, k, si << 1 | 1, mid + 1, hi);
		return getSmaller(l, r, k, si << 1, lo, mid) + getSmaller(l, r, k, si << 1 | 1, mid + 1, hi);
	}

	void update(const int i, int c) {
		int si = leaves[i];
		int prevVal = st[si].v;
		st[si] = StVal(c);
		for (si >>= 1; si; si >>= 1) {
			erase(st[si].treap, prevVal);
			insert(st[si].treap, new node(c));
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}