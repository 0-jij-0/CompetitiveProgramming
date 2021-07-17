#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int dif = 0;
		a.resize(n); b.resize(n);
		for (auto& x : a) { cin >> x; dif += x; }
		for (auto& x : b) { cin >> x; dif -= x; }
		sort(a.begin(), a.end()); sort(b.begin(), b.end());
		int i = 0; while (i != n / 4) { dif += b[i] - a[i]; i++; }
		if (dif >= 0) { cout << 0 << '\n'; continue; }

		int round = n + 1, j = - 1 + n / 4; while (dif < 0) {
			if (round % 4 == 0) {
				dif += 100 - a[i];
				i++; round++; continue;
			}
			dif += 100;
			if (j != -1) { dif -= b[j]; j--; }
			round++; continue;
		}
		cout << round - n - 1 << '\n';
	}
	cin.ignore(2); return 0;
}