#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, t;
int DP[1002][1002];

struct edge {
	int u, v;
	edge(int _u, int _v) {
		u = _u; v = _v;
	}
};
struct node { 
	int time, cost;
	vector<edge> edges;
	
	node() { time = 0; cost = 0; }
};

vector<node> nodes;

int minCost(int cur, int timeLeft) {
	if (DP[cur][timeLeft] != -1) { return DP[cur][timeLeft]; }
	if (timeLeft == 0 && cur == 0) { return DP[0][0] = 0; }
	else if (timeLeft == 0) { return INT_MAX / 4; }

	int res = INT_MAX;
	for (auto &e : nodes[cur].edges) {
		int dif = timeLeft - t - nodes[e.v].time;
		if (dif >= 0) {
			int c = nodes[e.v].cost + minCost(e.v, dif);
			res = min(res, c);
		}
	}

	DP[cur][timeLeft] = res;
	return res;
}

void resetDP() {
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++)
			DP[i][j] = -1;
}

int main() {
	int x; cin >> x;
	cin >> n >> m >> t;
	nodes.resize(n); resetDP();

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		edge e1(a, b); edge e2(b, a);
		nodes[a].edges.push_back(e1);
		nodes[b].edges.push_back(e2);
	}
	for (int i = 0; i < n; i++) {
		int t2, p; cin >> t2 >> p;
		nodes[i].time = t2; nodes[i].cost = p;
	}

	cout << minCost(0, x) << endl;

	cin.ignore(2); return 0;
}