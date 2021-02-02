#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
 
struct node {
	ll val, time, subTime;
	int priority, size;
	node *l, *r;
 
	node() {}
	node(ll _r, ll _t) : val(_r), time(_t), priority(rand()), l(NULL), r(NULL), size(1) {}
 
	void updateSize() {
		size = 1 + (l ? l->size : 0) + (r ? r->size : 0);
		subTime = time + (l ? l->subTime : 0) + (r ? r->subTime : 0);
	}
};
int sz(node* t) { return t ? t->size : 0; }
ll subTime(node *t) { return t ? t->subTime : 0; }
 
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
 
//Inserts u into the treap rooted at t
void insert(node *&t, node *u) {
	if (!t) { t = u; }
	else if (u->priority > t->priority) { split(t, u->l, u->r, u->val); t = u; }
	else { insert(t->val <= u->val ? t->r : t->l, u); }
	if (t) t->updateSize();
}
 
//Erases the node with val k in the subtree of t
void erase(node *&t, int key) {
	if (!t) { return; }
	if (t->val == key) { node* tmp = t; merge(t, t->l, t->r); delete tmp; }
	else { erase(t->val < key ? t->r : t->l, key); }
	if (t) t->updateSize();
}
 
ll findTime(node *cur, ll key) {
	if (!cur) { return 0; }
	if (cur->val >= key) { return findTime(cur->l, key); }
	else { return cur->time + subTime(cur->l) + findTime(cur->r, key); }
}
 
void addAll(node *&to, node *from) {
	if (!from) { return; }
	insert(to, new node(from->val, from->time));
	addAll(to, from->l);
	addAll(to, from->r);
	delete from;
}
 
vector<ll> ra, ti, res;
 
struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};
struct Tnode { vector<edge> edges; };
 
struct tree {
	vector<Tnode> nodes;
	node *childTreap;	//Contains the set of the last node we called dfs on
	int root, n;
 
	tree(int _n, int _r = 0) : n(_n), root(_r) { nodes.resize(n); }
 
	void add_edge(int u, int v) {
		edge e1(u, v); edge e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
 
	void dfs(int u, int p) {
		node *treap = NULL;
		insert(treap, new node(ra[u], ti[u]));
		for (auto &e : nodes[u].edges) {
			if (e.v == p) { continue; }
			dfs(e.v, u);
			if (sz(childTreap) > sz(treap)) { swap(childTreap, treap); }
			addAll(treap, childTreap);
		}
		res[u] = findTime(treap, ra[u]);
		swap(childTreap, treap);
	}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n; cin >> n;
	tree t(n); ra.resize(n); ti.resize(n);
 
	for (int i = 0; i < n; i++) {
		int m, r, curT; cin >> m >> r >> curT;
		ra[i] = r; ti[i] = curT;
		if (m == -1) { t.root = i; }
		else { t.add_edge(m - 1, i); }
	}
 
	res.resize(n);
	t.dfs(t.root, -1);
	for (auto &x : res) { cout << x << '\n'; }
}