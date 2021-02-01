#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k >> s;
		int z = 0, o = 0, q = 0; bool ok = true;
		for (int i = 0; i < k; i++) {
			bool Z = false, O = false;
			for (int j = i; j < n; j += k)
				if (s[j] != '?') (s[j] == '0' ? Z : O) = true;
			if (Z && O) { ok = false; break; }
			if (Z || O) { (Z ? z : o)++; continue; }
			q++;
		}

		if (z > k / 2) { cout << "NO" << '\n'; continue; }
		if (o > k / 2) { cout << "NO" << '\n'; continue; }
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}