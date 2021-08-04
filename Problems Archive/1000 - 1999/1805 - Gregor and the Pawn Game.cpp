#include <iostream>
#include <string>
#include <array>
using namespace std;

array<string, 2> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; s.fill(string(n, '0'));
		for (auto& x : s) for (auto& y : x) cin >> y;

		int i = 0, res = 0; while (i < n) {
			if (s[1][i] == '0') { i++; continue; }
			if (i && s[0][i - 1] == '1') { res++; i++; continue; }
			if (s[0][i] == '0') { res++; i++; continue; }
			if (i != n - 1 && s[0][i + 1] == '1') { s[0][i + 1] = '0'; res++; }
			i++;			
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}