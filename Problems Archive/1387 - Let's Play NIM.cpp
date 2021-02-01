#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); map<int, int> m;
		for (auto &x : v) { cin >> x; m[x]++; }
		if (n % 2) { cout << "Second" << '\n'; continue; }
		bool ok = true; for (auto &x : m) if (x.second % 2) { ok = false; break; }
		cout << (ok ? "Second" : "First") << '\n';
	}
	cin.ignore(2); return 0;
}