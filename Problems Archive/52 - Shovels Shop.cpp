#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

map<int, int> offers;
vector<int> costs;
int sums[2000];
long long DP[2000];

void input(int &n, int &m, int &k) {
	multimap<int, int> min_costs;
	offers.clear(); costs.clear();
	multimap<int, int>::iterator it;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (costs.size() < k) {
			pair<int, int> p(a, i);
			min_costs.insert(p);
			continue;
		}
		it = min_costs.end(); it--;
		if (a > it->first) { continue; }
		it = min_costs.erase(it);
		pair<int, int> p(a, i);
		min_costs.insert(p);
	}

	it = min_costs.begin(); costs.push_back(it->first); it++;
	sums[0] = costs[0];
	for (int i = 1; i < k; i++) {
		costs.push_back(it->first); it++;
		sums[i] = sums[i - 1] + costs[i];
	}

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		if (x > k) { continue; }
		offers[x] = (y > offers[x]) ? y : offers[x];
	}
	for (int i = 0; i < k; i++) { DP[i] = -1; }
}

long long min_cost(int i) {
	if (i == -1) { return 0; }
	if (DP[i] != -1) { return DP[i]; }

	long long min = INT_MAX;
	map<int, int>::iterator it = offers.begin();
	for (; it != offers.end(); it++) {
		int t = it->first; if (t > i + 1) { continue; }
		int f = it->second; int p = t - f;
		long long cost = min_cost(i - t) + sums[i] - sums[i - p];
		min = (cost < min) ? cost : min;
	}
	if (min == INT_MAX) { return sums[i]; }
	DP[i] = min; return min;
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	input(n, m, k);
	cout << min_cost(k - 1) << endl;
	return 0;
}