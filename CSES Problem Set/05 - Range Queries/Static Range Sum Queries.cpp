#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int n, q; cin >> n >> q; v.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x; v[i] = v[i - 1] + x;
	}
	while (q--) {
		int a, b; cin >> a >> b;
		cout << v[b] - v[a - 1] << '\n';
	}
}