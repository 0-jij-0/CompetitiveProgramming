#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		bool ok = false;
		for(int i = 1; i < n; i++)
			if (v[i] >= v[i - 1]) { ok = true; break; }
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}