#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, d; cin >> n >> d; v.resize(n);
		for (auto& x : v) { cin >> x; }
		int g = gcd(n, d); vector<vector<int>> V(g);

		bool ok = true; int N = n / g;
		for (int i = 0; i < g; i++) {
			int a = 0; bool f = true;
			for (int j = i; f || j != i; j = (j + d) % n) {
				f = false; j == i ? a = v[j] : a &= v[j];
				V[i].push_back(v[j]);
			}
			for (int j = 0; j < N; j++) V[i].push_back(V[i][j]);
			if (a) { ok = false; break; }
		}
		if (!ok) { cout << "-1\n"; continue; }

		int res = 0; N <<= 1;
		for (int i = 0; i < g; i++)
			for (int k = 0; k < 20; k++) {
				int cur = 0, ans = 0, j = 0;
				while (j != N) {
					if ((V[i][j] & (1 << k)) == 1) { cur++; j++; continue; }
					ans = max(ans, cur); cur = 0; j++;
				}

				res = max({ res, ans, cur });
			}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}