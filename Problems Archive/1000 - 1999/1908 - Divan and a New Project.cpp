#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v, res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		auto comp = [&](const int& i, const int& j) {
			return v[i] < v[j];
		};
		vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
		sort(idx.rbegin(), idx.rend(), comp);

		res.resize(n); ll ans = 0, l = -1, r = 1;
		for (auto& x : idx) {
			if (abs(l) < r) { res[x] = l; ans += v[x] * abs(l) << 1; l--; }
			else { res[x] = r; ans += v[x] * (r << 1); r++; }
		}

		cout << ans << '\n' << 0 << '\n';
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}