#include <iostream>
#include <vector>
using namespace std;

vector<int> a, v;

int main() {
	int n, m; cin >> n >> m; v.resize(n); a.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; a[--v[i]] = i; }
	int res = 1; for (int i = 1; i < n; i++) res += (a[i] < a[i - 1]);

	while (m--) {
		int x, y; cin >> x >> y; x--; y--;
		int i = v[x], j = v[y]; if (i > j) { swap(i, j); }

		if (j == i + 1) {
			if (i && a[i] < a[i - 1]) { res--; }
			if (a[j] < a[i]) { res--; }
			if (j != n - 1 && a[j + 1] < a[j]) { res--; }
			swap(a[i], a[j]); swap(v[x], v[y]);
			if (i && a[i] < a[i - 1]) { res++; }
			if (a[j] < a[i]) { res++; }
			if (j != n - 1 && a[j + 1] < a[j]) { res++; }
		}
		else {
			if (i && a[i] < a[i - 1]) { res--; }
			if (a[i + 1] < a[i]) { res--; }
			if (a[j] < a[j - 1]) { res--; }
			if (j != n - 1 && a[j + 1] < a[j]) { res--; }
			swap(a[i], a[j]); swap(v[x], v[y]);
			if (i && a[i] < a[i - 1]) { res++; }
			if (a[i + 1] < a[i]) { res++; }
			if (a[j] < a[j - 1]) { res++; }
			if (j != n - 1 && a[j + 1] < a[j]) { res++; }
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}