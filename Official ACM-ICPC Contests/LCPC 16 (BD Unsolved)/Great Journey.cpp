#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<int, vector<int>> sum, dif;
vector<int> a, b; int n;

int bfs(int s) {
	queue<int> q; q.push(s); 
	vector<int> d(n, -1); d[s] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int S = a[cur] + b[cur], D = a[cur] - b[cur];

		if (sum.count(S)) for (auto& x : sum[S]) {
			if (d[x] != -1) { continue; }
			d[x] = 1 + d[cur]; q.push(x);
		}

		if (dif.count(D)) for (auto& x : dif[D]) {
			if (d[x] != -1) { continue; }
			d[x] = 1 + d[cur]; q.push(x);
		}

		sum.erase(S); dif.erase(D);
	}

	return d[n - 1];
}

int main() {
	freopen("great.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n; a.resize(n); b.resize(n);
		for (auto& x : a) { cin >> x; }
		for (auto& x : b) { cin >> x; }

		sum.clear(); dif.clear();
		for (int i = 0; i < n; i++) {
			sum[a[i] + b[i]].push_back(i);
			dif[a[i] - b[i]].push_back(i);
		}

		cout << bfs(0) << '\n';
	}
	cin.ignore(2); return 0;
}