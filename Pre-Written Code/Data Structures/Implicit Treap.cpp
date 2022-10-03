#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	int priority, size, val;
	int sum, prefVal, sufVal, maxRange;
	bool pref0, suf0;
	bool reverse, flip, setTo0, setTo1;
	node* l, * r;

	node() {}
	node(int v) :val(v), priority(rand()), l(NULL), r(NULL), size(1) {
		sum = prefVal = sufVal = val;
		pref0 = suf0 = val == 0;
		maxRange = 1;
		reverse = flip = setTo0 = setTo1 = 0;
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

		int midVal = 1;
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
	if (t->flip) {
		t->flip = 0; t->val ^= 1;
		t->sum = t->size - t->sum;
		t->pref0 ^= 1; t->suf0 ^= 1;
		if (t->l) { 
			t->l->flip ^= 1;
			if (t->l->flip) {
				if (t->l->setTo0) { t->l->setTo1 = 1; t->l->setTo0 = t->l->flip = 0; }
				else if (t->l->setTo1) { t->l->setTo0 = 1; t->l->setTo1 = t->l->flip = 0; }
			}
		}
		if (t->r) {
			t->r->flip ^= 1;
			if (t->r->flip) {
				if (t->r->setTo0) { t->r->setTo1 = 1; t->r->setTo0 = t->r->flip = 0; }
				else if (t->r->setTo1) { t->r->setTo0 = 1; t->r->setTo1 = t->r->flip = 0; }
			}
		}
	}
	if (t->setTo0) {
		t->setTo0 = 0; t->val = 0; 
		t->sum = 0;
		t->pref0 = t->suf0 = 1;
		t->prefVal = t->sufVal = t->maxRange = t->size;
		if (t->l) {
			t->l->setTo0 = 1;
			if (t->l->setTo0) { t->l->flip = t->l->setTo1 = 0; }
		}
		if (t->r) {
			t->r->setTo0 = 1;
			if (t->r->setTo0) { t->r->flip = t->r->setTo1 = 0; }
		}
	}
	if (t->setTo1) {
		t->setTo1 = 0; t->val = 1;
		t->sum = t->size;
		t->pref0 = t->suf0 = 0;
		t->prefVal = t->sufVal = t->maxRange = t->size;
		if (t->l) {
			t->l->setTo1 = 1;
			if (t->l->setTo1) { t->l->flip = t->l->setTo0 = 0; }
		}
		if (t->r) {
			t->r->setTo1 = 1;
			if (t->r->setTo1) { t->r->flip = t->r->setTo0 = 0; }
		}
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

void setRangeVal(node*& t, int l, int r, int val) {
	if (l > r) { return; }
	node* t1, * t2, * t3;
	split(t, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	if (t2) {
		if (val) { t2->setTo1 = 1; t2->setTo0 = t2->flip = 0; }
		else { t2->setTo0 = 1; t2->setTo1 = t2->flip = 0; }
		operation(t2);
	}
	merge(t, t1, t2);
	merge(t, t, t3);
}

void flipRange(node*& t, int l, int r) {
	if (l > r) { return; }
	node* t1, * t2, * t3;
	split(t, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	if (t2) {
		t2->flip ^= 1;
		if (t2->flip) {
			if (t2->setTo0) { t2->setTo1 = 1; t2->setTo0 = t2->flip = 0; }
			else if (t2->setTo1) { t2->setTo0 = 1; t2->setTo1 = t2->flip = 0; }
		}
		operation(t2);
	}
	merge(t, t1, t2);
	merge(t, t, t3);
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

int findSum(node*& t, int l, int r) {
	if (l > r) { return 0; }
	node* t1, * t2, * t3;
	split(t, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	operation(t2);
	int res = t2 ? t2->sum : 0;
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

	int n, q; cin >> n >> q;
	string s; cin >> s;
	node* treap = NULL;
	for (int i = 0; i < n; i++) { insert(treap, new node(s[i] - '0')); }
	
	while (q--) {
		int t, l, r; cin >> t >> l >> r;
		if (t == 1) {
			flipRange(treap, l, r);
		}
		else if (t == 2) {
			reverse(treap, l, r);
		}
		else {
			int ones = findSum(treap, l, r);
			int zeros = r - l + 1 - ones;
			setRangeVal(treap, l, l + zeros - 1, 0);
			setRangeVal(treap, l + zeros, r, 1);
		}

		operation(treap);
		cout << treap->maxRange << '\n';
	}
}