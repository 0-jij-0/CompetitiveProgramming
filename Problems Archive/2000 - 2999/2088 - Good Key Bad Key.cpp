#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;
typedef long long ll;

vector<int> v; int n; ll k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> k; v.resize(n);
		for (auto& x : v) cin >> x;

		ll cur = accumulate(v.begin(), v.end(), 0ll) - k * n;

		set<int> active; ll res = cur;
		for (int i = n - 1; i >= 0; i--) {
			active.insert(i); cur += k;
			set<int> toBeRemoved;
			for (auto& x : active) { 
				cur -= (v[x] + 1) / 2; 
				v[x] >>= 1; if (!v[x]) toBeRemoved.insert(x);
			}
			for (auto& x : toBeRemoved) active.erase(x);
			res = max(res, cur);
		}

		cout << res << '\n';
	}
}