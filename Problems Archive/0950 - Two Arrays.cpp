#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

vector<int> a, b, sufMin;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	a.resize(n); b.resize(m); sufMin.resize(n);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }
	sufMin.back() = a.back();
	for (int i = n - 2; i >= 0; i--)
		sufMin[i] = min(sufMin[i + 1], a[i]);

	if (sufMin[0] != b[0]) { cout << 0 << '\n'; return 0; }
	if (m == 1 && sufMin[0] == b[0]) { cout << 1 << '\n'; return 0; }

	int i = 0, j = 0; bool ok = true;
	while (i < n && j < m - 1) {
		if (sufMin[i] > b[j + 1]) { ok = false; break; }
		if (sufMin[i] < b[j + 1]) { i++; continue; }
		j++; i++;
	}
	if (!ok || j != m - 1) { cout << 0 << '\n'; return 0; }
	i = 0, j = 0; int k = 1; ll res = 1;

	while (sufMin[i] == b[0]) { i = j = j + 1; }
	while (j < n) {
		if (sufMin[i] < b[k]) { i = j = j + 1; continue; }
		if (sufMin[j] > b.back()) { break; }
		if (sufMin[j] == sufMin[i]) { j++; continue; }
		res = (res * (j - i)) % mod; i = j; k++;
	}
	if (j != i) { res = res * (j - i) % mod; }
	cout << res << '\n'; cin.ignore(2); return 0;
}