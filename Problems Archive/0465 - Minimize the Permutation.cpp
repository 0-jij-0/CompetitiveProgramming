#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n; p.resize(n);
		for (auto &x : p) { cin >> x; }
		int l = 0, c = n - 1;
		while (c != 0 && l != n - 1) {
			int idx = min_element(p.begin() + l, p.end()) - p.begin();
			if (idx == l) { l++; continue; }
			int temp = idx;
			while (idx != l) { swap(p[idx], p[idx - 1]); idx--; c--; }
			l = temp;
		}
		for (auto &x : p) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}