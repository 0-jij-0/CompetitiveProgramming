#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v; int n, s;

bool check(int k) {
	vector<ll> a = v;
	for (int i = 0; i < n; i++) { a[i] += (ll)(i + 1) * k; }
	sort(a.begin(), a.end());
	return accumulate(a.begin(), a.begin() + k, 0ll) <= s;
}

int findMin() {
	int l = 0, r = n;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		bool b = check(mid);
		b ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	cin >> n >> s; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int res = findMin();
	for (int i = 0; i < n; i++) { v[i] += (ll)(i + 1) * res; }
	sort(v.begin(), v.end());
	cout << res << ' ' << accumulate(v.begin(), v.begin() + res, 0ll) << endl;
	cin.ignore(2); return 0;
}