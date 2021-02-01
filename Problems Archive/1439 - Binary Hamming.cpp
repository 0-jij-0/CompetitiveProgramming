#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;

int main() {
	freopen("hamming.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> a >> b;
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		int res = 0; for (int i = 0; i < n; i++)
			res += (a[i] != b[i]);
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}