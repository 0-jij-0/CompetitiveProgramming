#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int z = 0, o = 0, e = 0;
		for (auto &x : v) {
			e += (x.size() % 2 == 0);
			for (auto &c : x) {
				if (c - '0') { o++; }
				else { z++; }
			}
		}
		if (e == n && z % 2) { cout << n - 1 << endl; continue; }
		else { cout << n << endl; continue; }
	}
	cin.ignore(2); return 0;
}