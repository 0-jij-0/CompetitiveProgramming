#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> Fib(45, 0);

int main() {
	freopen("diff.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	Fib[1] = 1; for (int i = 2; i < 45; i++)
		Fib[i] = Fib[i - 1] + Fib[i - 2];

	int t; cin >> t; while (t--) {
		int n; cin >> n; vector<int> a(n); map<int, int> DP;
		for (auto& x : a) { cin >> x; DP[x] = 0; }

		auto getDP = [&](int x) { return DP.count(x) ? 1 + DP[x] : 1; };
		int res = 0; for (auto& x : a) for (auto& f : Fib)
			res = max(res, DP[x] = max({ DP[x], getDP(x - f), getDP(x + f)}));

		cout << res << '\n';
	}
}