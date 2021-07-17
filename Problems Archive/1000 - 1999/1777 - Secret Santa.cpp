#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int dp[200002];
vector<int> v, idx, first;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; first.resize(n);
		idx.resize(n); iota(idx.begin(), idx.end(), 0);
		v.resize(n); for (auto& x : v) { cin >> x; x--; }

		auto comp = [&](const int& i, const int& j) { return v[i] < v[j]; };
		sort(idx.begin(), idx.end(), comp);

		int prev = -1; dp[0] = 0;
		for (int i = 0; i < n; i++) {
			if (v[idx[i]] == prev) { continue; }
			first[v[idx[i]]] = i; prev = v[idx[i]];
		}

		for (int i = 1; i <= n; i++)
			dp[i] = max(dp[i - 1], 1 + dp[first[v[idx[i - 1]]]]);

		//for (auto& x : idx) cout << x + 1 << ' '; cout << '\n';
		//for (int i = 1; i <= n; i++) cout << dp[i] << ' '; cout << '\n';

		vector<int> res(n, -1), vis(n, -1); int N = n;
		cout << dp[n] << '\n'; while (N > 0) {
			if (dp[N] == dp[N - 1]) { N--; continue; }
			res[idx[N - 1]] = v[idx[N - 1]];
			vis[v[idx[N - 1]]] = 1;
			N = first[v[idx[N - 1]]];
		}

		//for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
		if (dp[n] != n) {
			vector<int> R, V;
			for (int i = 0; i < n; i++) {
				if (res[i] == -1) { R.push_back(i); }
				if (vis[i] == -1) { V.push_back(i); }
			}
			if (V.size() != 1 || V.front() != R.front()) {
				int i = 0, j = (int)V.size() - 1;
				while (j >= 0) {
					if (R[i] != V[j]) { res[R[i++]] = V[j--]; continue; }
					if (i != 0) { res[R[i]] = V[j]; swap(res[R[i]], res[R[i - 1]]); i++; j--; continue; }
					if (j != 0) { res[R[i]] = V[j - 1]; res[R[i + 1]] = V[j];  i += 2; j -= 2; }
				}
			}
			else {
				int tar = v[V.front()];
				for (int i = 0; i < n; i++)
					if (res[i] == tar) { tar = i; break; }
				res[V.front()] = v[V.front()]; res[tar] = V.front();
			}
		}
		for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}