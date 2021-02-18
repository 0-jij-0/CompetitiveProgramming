#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }

		ll cur = 0; bool ok = true;
		for (int i = 0; i < n; i++) {
			v[i] += cur; 
			if (v[i] < i) { ok = false; break; }
			cur = v[i] - i;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}