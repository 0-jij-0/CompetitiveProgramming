#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v; int n, k;

bool check(ll M) {
	int res = 0; ll cur = 0;
	for (auto& x : v) {
		if (cur + x <= M) { cur += x; }
		else { cur = x; res++; }
	}
	return res < k;
}

ll minSegmentMax() {
	ll L = *max_element(v.begin(), v.end()), R = 1ll << 50;
	while (L != R) {
		ll M = (L + R) >> 1;
		check(M) ? R = M : L = M + 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;
	cout << minSegmentMax() << '\n';
}