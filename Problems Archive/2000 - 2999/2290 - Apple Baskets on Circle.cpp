#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll k; cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;

	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int& i, int& j) {
		return v[i] < v[j];
	});

	vector<ll> D(n); D[0] = v[idx[0]];
	for (int i = n - 1; i > 0; i--)
		D[i] = v[idx[i]] - v[idx[i - 1]];

	ll rem = 0; int i = 0; while (k) {
		if (k - (n - i) * D[i] > 0) {
			k -= (n - i) * D[i];
			rem += D[i++]; continue;
		}

		rem += k / (n - i); k %= (n - i);
		for (int j = 0; j < n; j++)
			v[j] = max(0ll, v[j] - rem);

		for(int j = 0; j < n && k; j++)
			if (v[j]) { k--; v[j]--; }
	}

	for (auto& x : v) cout << x << ' '; cout << '\n';
}