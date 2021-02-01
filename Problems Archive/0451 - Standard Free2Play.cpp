#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int q; cin >> q;
	while (q--) {
		int h, n; cin >> h >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int res = 0; int j = 0;
		while (h > 2) {
			while (j < n && v[j] >= h) { j++; }
			if (j == n) { break; }
			if (j < n && v[j] != h - 1) { h = v[j] + 1; continue; }
			if (j < n - 1 && v[j + 1] == h - 2) { h -= 2; continue; }
			res++; h -= 2;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}