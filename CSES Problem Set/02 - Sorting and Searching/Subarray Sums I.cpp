#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v; int n;

int main() {
	int x; cin >> n >> x; v.resize(n);
	for (auto &x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());
	int res = binary_search(v.begin(), v.end(), x);
	for (int i = 0; i < n; i++)
		res += binary_search(v.begin() + i + 1, v.end(), x + v[i]);
	cout << res << '\n';
}