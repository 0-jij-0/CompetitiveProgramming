#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<long long, int>>> min_cost;
vector<pair<pair<long long, int>, int>> g;
int n, m, k, s;

bool check_day(int d) {
	vector<pair<long long, int>> v;
	for (auto &x : g) { v.push_back(x.first); }
	for(auto &x : v) {
		x.first *= min_cost[x.second][d].first;
	}
	sort(v.begin(), v.end()); long long sum = 0;
	for (int i = 0; i < k; i++) { sum += v[i].first; }
	return (sum <= s);
}

int min_day() {
	int l = 0, r = n - 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check_day(mid);
		if (b) { r = mid; }
		else { l = mid + 1; }
	}
	return l;
}

int main() {
	cin >> n >> m >> k >> s; min_cost.resize(2);
	min_cost[0].resize(n); min_cost[1].resize(n);
	g.resize(m);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; pair<long long, int> p(a, i + 1);
		if (i == 0) { min_cost[0][0] = p; }
		else { min_cost[0][i] = min(min_cost[0][i - 1], p); }
	}
	for (int i = 0; i < n; i++) {
		int b; cin >> b; pair<long long, int> p(b, i + 1);
		if (i == 0) { min_cost[1][0] = p; }
		else { min_cost[1][i] = min(min_cost[1][i - 1], p); }
	}
	for (int i = 0; i < m; i++) {
		int t, c; cin >> t >> c;
		pair<long long, int> p(c, t - 1);
		g[i] = { p, i + 1 };
	}
	if (!check_day(n - 1)) { cout << -1 << endl; }
	else {
		int d = min_day();
		cout << d + 1 << endl;
		for (auto &x : g) {
			x.first.first *= min_cost[x.first.second][d].first;
		}
		sort(g.begin(), g.end());
		for (int i = 0; i < k; i++) {
			cout << g[i].second << ' ' << min_cost[g[i].first.second][d].second << endl;
		}
	}
	cin.ignore(2); return 0;
}