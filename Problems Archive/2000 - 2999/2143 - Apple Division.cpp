#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
vector<int> v;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n); ll ans = 0;
	for (auto &x : v) { cin >> x; ans += x; }

	for (int i = 0; i < 1 << (n - 1); i++) { 
		ll cur = 0; for (int j = 0; j < n; j++)
			(i >> j & 1) ? cur += v[j] : cur -= v[j];
		ans = min(ans, abs(cur));
	}
	cout << ans << '\n';
}