#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, p;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m; v.resize(n);
		p.clear(); p.resize(n, 0);
		for (auto &x : v) { cin >> x; }
		for (int i = 0; i < m; i++) {
			int x; cin >> x; p[x - 1]++;
		}

		int i = 0, j = 0;
		while (j < n) {
			if (!p[i]) { i = j = j + 1; continue; }
			if (p[j]) { j++; continue; }
			sort(v.begin() + i, v.begin() + j + 1);
			i = j = j + 1;
		}

		bool b = true;
		for(int i = 1; i < n; i++)
			if (v[i] < v[i - 1]) { b = false; break; }

		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}