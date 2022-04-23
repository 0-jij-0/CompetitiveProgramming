#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end());
		map<string, ll> freq;
		for (auto& x : v) freq[x]++;

		ll res = 0; for (auto& x : freq)
			res -= (x.second * (x.second - 1));

		map<string, ll> wildcards;
		for (auto x : v) {
			char c = x[0]; x[0] = '0';
			res += wildcards[x]++;
			x[0] = c; x[1] = '0';
			res += wildcards[x]++;
		}

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}