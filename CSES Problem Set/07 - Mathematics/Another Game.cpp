#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; x &= 1; }
		bool b = count(v.begin(), v.end(), 1);
		cout << (b ? "first" : "second") << '\n';
	}
}