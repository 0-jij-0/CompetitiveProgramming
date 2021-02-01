#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v, a;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		a.resize(n); v.resize(k);
		for (auto &x : a) { cin >> x; }
		for (auto &x : v) { cin >> x; }
		sort(a.begin(), a.end());
		sort(v.rbegin(), v.rend());
		int curL = 0, curR = n - 1; ll res = 0;
		while (!v.empty() && v.back() == 1) { res += 2 * a[curR--]; v.pop_back(); }

		for (auto &x : v) {
			res += a[curR--]; res += a[curL];
			curL += x - 1;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}