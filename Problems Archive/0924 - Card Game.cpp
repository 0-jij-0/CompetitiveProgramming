#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;
const int SVSZ = 200005;
int spf[SVSZ];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

bool isPrime(int x) { return spf[x] == x; }

struct Card {
	int p, c, l; Card() {}
	bool operator <(const Card &rhs) {
		if (abs(c - rhs.c) % 2) { return rhs.c % 2; }
		return c < rhs.c;
	}
	operator int() { return c; }
};

vector<Card> v;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<vector<ll>> capacity;
	vector<int> parent;

	graph(int _n) : n(_n) { nodes.resize(n); capacity.resize(n, vector<ll>(n, 0)); }

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
		capacity[u][v] += c;
		//capacity[v][u] += c; //if undirected edge
	}

	//O(VE^2)
	ll maxflow(int s, int t) {
		parent.resize(n);
		ll flow = 0, new_flow = maxFlowBFS(s, t, parent);

		while (new_flow) {
			flow += new_flow; int cur = t;
			while (cur != s) {
				int prev = parent[cur];
				capacity[prev][cur] -= new_flow;
				capacity[cur][prev] += new_flow;
				cur = prev;
			}
			new_flow = maxFlowBFS(s, t, parent);
		}
		return flow;
	}

	ll maxFlowBFS(int s, int t, vector<int>& parent) {
		fill(parent.begin(), parent.end(), -1);	parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, INF });

		while (!q.empty()) {
			int cur = q.front().first; ll flow = q.front().second; q.pop();
			for (auto &e : nodes[cur].edges) {
				int next = e.v;
				if (parent[next] == -1 && capacity[cur][next]) {
					parent[next] = cur;
					ll new_flow = min(flow, capacity[cur][next]);
					if (next == t) { return new_flow; }
					q.push({ next, new_flow });
				}
			}
		}
		return 0;
	}
};

bool check(int M, const int &k) {
	vector<Card> cards;
	int n = 0, m = 0, res = 0;
	bool one = false; int maxP = 0;
	for (auto &x : v) {
		if (x.l > M) { continue; }
		if (x.c == 1 && !one) { cards.push_back(x); maxP = x.p; m++; one = true; continue; }
		if (x.c == 1) { maxP = max(maxP, x.p); continue; }
		cards.push_back(x); res += x.p;
		(x.c % 2 ? m : n)++;
	}
	if (one) { cards[n].p = maxP; res += maxP; }
	if (res < k) { return false; }
	if (n == 0 || m == 0) { return res >= k; }
	graph g(n + m + 2);
	for (int i = 0; i < n; i++)
		for (int j = n; j < n + m; j++)
			if (isPrime(cards[i] + cards[j]))
				g.add_edge(i + 1, j + 1, INF);
	for (int i = 0; i < n; i++)
		g.add_edge(0, i + 1, cards[i].p);
	for (int i = n; i < n + m; i++)
		g.add_edge(i + 1, n + m + 1, cards[i].p);

	int x = g.maxflow(0, n + m + 1);
	return (res - x) >= k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k; v.resize(n); buildSieve();
	for (auto &x : v) { cin >> x.p >> x.c >> x.l; }
	sort(v.begin(), v.end());

	int l = 0, r = 100001;
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check(mid, k);
		b ? r = mid : l = mid + 1;
	}
	cout << (l == 100001 ? -1 : l) << '\n';
	cin.ignore(2); return 0;
}