#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v; ll n; int k;

void inclusionExclusion(int i, ll cur, ll &res, bool odd) {
	if (i == k) { odd ? res += n / cur : res -= n / cur; return; }
	inclusionExclusion(i + 1, cur, res, odd);
	if (v[i] <= n / cur) inclusionExclusion(i + 1, cur *= v[i], res, odd ^ 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k; v.resize(k);
	for (auto& x : v) { cin >> x; }

	ll res = 0;
	inclusionExclusion(0, 1, res, false);
	cout << res + n << '\n';
}