#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	cout << max(2 * v.back(), accumulate(v.begin(), v.end(), 0ll)) << '\n';
}