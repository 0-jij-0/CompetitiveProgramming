#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
 
 
struct node {
	int val, priority, size;	//size accounts for duplicates here
	int freq;
	node* l = NULL, * r = NULL;
 
	node() {}
	node(int v) :val(v), priority(rand()), l(NULL), r(NULL), size(1), freq(1) {}
 
	void updateSize() {
		size = freq + (l ? l->size : 0) + (r ? r->size : 0);
	}
};
 
int sz(node* t) { return t ? t->size : 0; }
 
//Splits the subtree rooted at t into two trees according to curval (l <= and r >)
//It will set l as the root of the l subtree and r as the root of the r subtree
void split(node* t, node*& l, node*& r, int curVal) {
	if (!t) { l = r = NULL; }
	else if (t->val <= curVal) { split(t->r, t->r, r, curVal); l = t; }
	else { split(t->l, l, t->l, curVal); r = t; }
	if (t) t->updateSize();
}
 
//merges two treaps l and r and stores the root in t
//assumes nodes in l have < vals than nodes in r
void merge(node*& t, node* l, node* r) {
	if (!l || !r) { t = l ? l : r; }
	else if (l->priority > r->priority) { merge(l->r, l->r, r); t = l; }
	else { merge(r->l, l, r->l); t = r; }
	if (t) t->updateSize();
}
 
//Use as a check in case of duplicates
bool find(node* cur, int key, int add = 0) {
	if (!cur) { return false; }
	if (cur->val == key) { cur->freq += add; cur->updateSize(); return cur->freq > 0; }
	bool b = find(cur->val < key ? cur->r : cur->l, key, add);
	if (b && add) cur->updateSize();
	return b;
}
 
//Inserts u into the treap rooted at t
void insertR(node*& t, node* u) {
	if (!t) { t = u; }
	else if (u->priority > t->priority) { split(t, u->l, u->r, u->val); t = u; }
	else { insertR(t->val <= u->val ? t->r : t->l, u); }
	if (t) t->updateSize();
}
//Call this one; deals with duplicates
void insert(node*& t, node* u) { if (!find(t, u->val, 1)) { insertR(t, u); } }
 
//Erases the node with val k in the subtree of t
void erase(node*& t, int key) {
	if (!t) { return; }
	if (!find(t, key, -1)) {
		if (t->val == key) { node* tmp = t; merge(t, t->l, t->r); delete tmp; }
		else { erase(t->val < key ? t->r : t->l, key); }
		if (t) t->updateSize();
	}
}
 
//Find number of elements <= key
int count(node* cur, int key) {
	if (!cur) { return 0; }
	if (cur->val > key) { return count(cur->l, key); }
	else { return sz(cur->l) + cur->freq + count(cur->r, key); }
}
 
struct query {
	int idx, id;
	bool shop, rem;
	int Q;
 
	query(int _id, int i, int q, bool s = false, bool r = false): id(_id), idx(i), Q(q), shop(s), rem(r) {}
 
	bool operator<(const query& rhs) {
		if (idx != rhs.idx) { return idx < rhs.idx; }
		if (shop != rhs.shop) { return shop; }
		return false;
	}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("business.in", "r", stdin);
 
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<query> queries;
		vector<int> ans(m);
		for (int i = 0; i < n; i++) {
			int x, q, r; cin >> x >> q >> r;
			queries.push_back(query(-1, x, q - x, 1, 0));
			queries.push_back(query(-1, x + r + 1, q - x, 1, 1));
		}
		for (int i = 0; i < m; i++) {
			int y, d; cin >> y >> d;
			queries.push_back(query(i, y, d, 0, 0));
		}
		sort(queries.begin(), queries.end());
 
		node* treap = NULL;
		for (auto& q : queries) {
			if (q.shop) {
				if (q.rem) { erase(treap, q.Q); }
				else { insert(treap, new node(q.Q)); }
			}
			else {
				int needed = q.Q - q.idx;
				ans[q.id] = sz(treap) - count(treap, needed - 1);
			}
		}
 
		for (auto& x : ans) { cout << x << ' '; } cout << '\n';
	}
}