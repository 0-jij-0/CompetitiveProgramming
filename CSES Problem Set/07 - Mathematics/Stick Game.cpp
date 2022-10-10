#include <bits/stdc++.h>
using namespace std;

vector<int> p, res;

int main() {
	int n, k; cin >> n >> k; 
	res.resize(n + 1); p.resize(k);
	for (auto &x : p) { cin >> x; }
	res[0] = 0; for (int i = 1; i <= n; i++) {
		vector<bool> v(k, 0); for (auto &x : p)
			if (i - x >= 0) v[res[i - x]] = true;
		res[i] = find(v.begin(), v.end(), false) - v.begin();
	}
	for (int i = 1; i <= n; i++) cout << (res[i] ? 'W' : 'L');
	cout << '\n'; 
}