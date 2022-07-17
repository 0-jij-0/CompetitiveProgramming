#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		bool ok = true;
		for (auto& x : v) ok = ok && (x % v[0] == 0);
		cout << (ok ? "YES" : "NO") << '\n';
	}
}