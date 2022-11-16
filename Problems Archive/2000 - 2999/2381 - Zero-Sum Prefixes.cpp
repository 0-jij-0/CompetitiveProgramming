#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v; int n;

int maxPref(int l, int r) {
	map<ll, int> freq; int res = 0; ll cur = 0; 
	for (int i = l; i < r; i++) 
		res = max(res, ++freq[cur += v[i]]);
	
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		int i = 0, res = 0; ll cur = 0;
		while (i < n && v[i]) res += (cur += v[i++]) == 0;

		for (int j = i + 1; i < n; i = j++) {
			while (j < n && v[j]) j++;
			res += maxPref(i, j);
		}

		cout << res << '\n';
	}
}