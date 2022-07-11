#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q; v.resize(n);
		for (auto& x : v) cin >> x;
		map<int, int> first, last;
		
		for (int i = 0; i < n; i++) last[v[i]] = i;
		for (int i = n; i > 0; i--) first[v[i - 1]] = i - 1;

		while (q--) {
			int a, b; cin >> a >> b;
			if (!first.count(a) || !first.count(b)) { cout << "NO\n"; continue; }
			cout << (first[a] < last[b] ? "YES" : "NO") << '\n';
		}
	}
}