#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll s; cin >> n >> s; v.resize(n);
	for (auto& x : v) cin >> x;

	ll res = 0, cur = 0;
	for (int i = 0, j = 0; i < n; cur -= v[i++]) {
		while (j < n && cur + v[j] <= s) { cur += v[j++]; }
		res += 1ll * (j - i) * (j - i + 1) / 2;
	}

	cout << res << '\n';
}