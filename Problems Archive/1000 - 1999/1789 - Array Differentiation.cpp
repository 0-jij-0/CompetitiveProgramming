#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> a; set<int> s;
vector<int> pow3(11, 1);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i < 11; i++) pow3[i] = 3 * pow3[i - 1];

	int t; cin >> t; while (t--) {
		int n; cin >> n; a.resize(n); s.clear();
		for (auto& x : a) { cin >> x; s.insert(x); }
		if (s.size() < n) { cout << "YES\n"; continue; }
		if (s.count(0)) { cout << "YES\n"; continue; }

		bool ok = false;
		for (int i = 0; i < n && !ok; i++) {
			for (int m = 1; m < pow3[n]; m++) {
				int cur = 0, mask = m;
				for (int j = 0; j < n; j++, mask /= 3) {
					if (j == i) { continue; }
					if (mask % 3 == 1) { cur += a[j]; }
					if (mask % 3 == 2) { cur -= a[j]; }
				}
				if (cur == a[i]) { ok = true; break; }
			}
		}

		cout << (ok ? "YES\n" : "NO\n");
	}

	cin.ignore(2); return 0;
}