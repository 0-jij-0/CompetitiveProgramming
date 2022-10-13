#include <bits/stdc++.h>
using namespace std;

vector<int> P;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int m; cin >> m; P.resize(m);
		for (auto& x : P) { cin >> x; --x; }

		int res = 0; bool ok = true;
		
		while (P.size() > 1 && ok) {
			vector<int> newP; int n = (int)P.size();
			for (int i = 0; i < n; i += 2) {
				int d = P[i] - P[i + 1]; res += d > 0;
				if (abs(d) != 1) { res = -1; ok = false; break; }
				newP.push_back(P[i] / 2);
			}
			P = move(newP);
		}

		cout << res << '\n';
	}
}