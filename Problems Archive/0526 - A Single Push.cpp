#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b, d;

bool check() {
	int i = 0, j = (int)d.size() - 1;
	while (i != j) {
		if (!d[i]) { i++; continue; }
		if (!d[j]) { j--; continue; }
		for (; i < j; i++)
			if (d[i] != d[j])
				return false;
	}
	return d[j] >= 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		a.resize(n); b.resize(n); d.resize(n);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }
		for (int i = 0; i < n; i++)
			d[i] = b[i] - a[i];

		cout << (check() ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}