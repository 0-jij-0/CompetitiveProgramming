#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		v.pop_back();

		ll res = accumulate(v.begin(), v.end(), 0ll);
		auto it = find_if(v.begin(), v.end(), [&](const int x) {return x != 0; });
		cout << res + count(it, v.end(), 0) << '\n';
	}
}