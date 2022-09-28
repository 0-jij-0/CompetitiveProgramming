#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, r; cin >> n >> r; v.resize(n);
	for (auto& x : v) cin >> x;

	ll res = 1ll * n * (n + 1) / 2;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && v[j] - v[i] <= r) { j++; }
		res -= j - i;
	}

	cout << res << '\n';
}