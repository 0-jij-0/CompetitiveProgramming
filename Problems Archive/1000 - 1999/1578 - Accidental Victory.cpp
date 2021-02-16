#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<pair<ll, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i + 1;
		}
		sort(v.begin(), v.end());
		vector<int> res(1, v.back().second);
		vector<ll> pref(n);

		pref[0] = v[0].first;
		for (int i = 1; i < n; i++)
			pref[i] = pref[i - 1] + v[i].first;

		for (int i = n - 2; i >= 0; i--) {
			if (pref[i] < v[i + 1].first) { break; }
			res.push_back(v[i].second);
		}

		sort(res.begin(), res.end()); cout << res.size() << '\n';
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}