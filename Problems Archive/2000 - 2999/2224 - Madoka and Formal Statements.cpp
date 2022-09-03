#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b, D;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; D.resize(n);
		a.resize(n); for (auto& x : a) cin >> x;
		b.resize(n); for (auto& x : b) cin >> x;
		for (int i = 0; i < n; i++) D[i] = b[i] - a[i];

		int req = 0; bool ok = true;
		for (int i = 0; i < n; i++) if(req || D[i]) {
			if ((D[i] -= req) < 0) { ok = false; break; }
			req = max(0, a[i] + req + D[i] - a[(i + 1) % n] - 1); a[i] = b[i];
		}

		cout << (ok && !req ? "YES" : "NO") << '\n';
	}
}