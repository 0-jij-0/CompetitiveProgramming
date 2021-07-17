#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	sort(v.begin(), v.end());

	ll res = 1; for (int i = 0; i < n; i++)
		res = (res * max(0, v[i] - i)) % mod;

	cout << res << '\n';
	cin.ignore(2); return 0;
}