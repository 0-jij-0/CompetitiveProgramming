#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }

		int blank = 0; bool ok = true;
		for (int i = 1; i < n; i++) {
			blank += v[i] - v[i - 1] - 1;
		}

		cout << (blank > 2 ? "NO" : "YES") << '\n';
	}

	cin.ignore(2); return 0;
}