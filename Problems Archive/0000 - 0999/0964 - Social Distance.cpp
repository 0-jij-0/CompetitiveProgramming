#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; string s; cin >> n >> k >> s;
		int res = 0, cnt = 0; bool p = true;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') { cnt++; continue; }
			cnt -= p ? k : 2 * k; p = false;
			if (cnt < 0) { cnt = 0; continue; }
			res += (cnt + k) / (k + 1); cnt = 0;
		}
		if (cnt == n) { cout << (n + k) / (k + 1) << endl; continue; }
		if (cnt > k) { res += cnt / (k + 1); }
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}