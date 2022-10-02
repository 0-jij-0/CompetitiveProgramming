#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 50;

vector<tuple<int, int, int>> edges;
vector<int> E; vector<ll> DP;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; 
	edges.resize(m); E.resize(k);
	for (auto& [a, b, c] : edges)
		cin >> a >> b >> c;

	for (auto& x : E) cin >> x;
	DP.resize(n, INF); DP[n - 1] = 0;
	for (int i = k - 1; i >= 0; i--) {
		auto [a, b, c] = edges[E[i] - 1];
		DP[a - 1] = min(DP[a - 1], c + DP[b - 1]);
	}

	cout << (DP[0] == INF ? -1 : DP[0]) << '\n';
}