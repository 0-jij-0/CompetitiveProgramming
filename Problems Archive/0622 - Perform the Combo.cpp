#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

vector<int> v; string s;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m >> s;
		v.clear(); v.resize(n, 0); v[0] = m + 1;
		while (m--) { int p; cin >> p; v[p]--; }
		partial_sum(v.begin(), v.end(), v.begin());
		vector<int> res(26, 0);
		for (int i = 0; i < n; i++) res[s[i] - 'a'] += v[i];
		for (auto &x : res) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}