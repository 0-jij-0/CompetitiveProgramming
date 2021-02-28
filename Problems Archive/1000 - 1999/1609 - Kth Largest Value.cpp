#include <iostream>
#include <vector>
using namespace std;

int f[2]; vector<int> v;

int main() {
	int n, q; cin >> n >> q; v.resize(n);
	for (auto& x : v) { cin >> x; f[x]++; }

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x; x--;
			f[v[x]]--; v[x] = 1 - v[x]; f[v[x]]++;
		}
		if (t == 2) {
			int k; cin >> k;
			cout << (f[1] >= k) << '\n';
		}
	}
	cin.ignore(2); return 0;
}