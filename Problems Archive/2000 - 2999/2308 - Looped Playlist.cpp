#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll p; cin >> n >> p; v.resize(n);
	for (auto& x : v) cin >> x;

	ll sum = accumulate(v.begin(), v.end(), 0ll);
	ll num = n * (p / sum); p %= sum;
	if (p == 0) { cout << 1 << ' ' << num << '\n'; return 0; }
	for (int i = 0; i < n; i++) v.push_back(v[i]);

	int start = -1, extra = n + 1; ll cur = 0;
	for (int i = 0, j = 0; i < n; cur -= v[i++]) {
		while (cur < p) { cur += v[j++]; }
		if (extra > j - i) { start = i; extra = j - i; }
	}

	cout << start + 1 << ' ' << num + extra << '\n';
}