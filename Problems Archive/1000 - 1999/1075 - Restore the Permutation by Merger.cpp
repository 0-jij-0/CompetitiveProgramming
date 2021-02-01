#include <iostream>
#include <vector>
using namespace std;

vector<int> v, freq, res;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v.resize(2 * n); res.resize(n);
		freq.clear(); freq.resize(n); int k = 0;
		for (auto &x : v) { cin >> x; x--; }
		for (int i = 0; i < 2 * n; i++) {
			if (freq[v[i]]) { continue; }
			freq[v[i]] = 1; res[k++] = v[i];
		}
		for (auto &x : res) { cout << x + 1 << ' '; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}