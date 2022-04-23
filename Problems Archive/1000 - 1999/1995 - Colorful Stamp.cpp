#include <iostream>
#include <string>
using namespace std;

string s;

bool canBeStamped(int l, int r) {
	int i = l; while (++i != r)
		if (s[i] != s[i - 1]) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		
		bool ok = true;
		int l = 0, r = 0; while (l != n) {
			if (s[l] == 'W') { r = l = l + 1; continue; }
			if (r != n && s[r] != 'W') { r++; continue; }
			ok = ok && canBeStamped(l, r); l = r;
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}