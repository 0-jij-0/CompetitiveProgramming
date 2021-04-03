#include <iostream>
#include <string>
using namespace std;

string a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> a >> b; int p = 0;
		for (char& c : a) (c == '0' ? p-- : p++);

		bool ok = true, flipped = false;
		for (int i = n - 1; i >= 0; i--) {
			char c = a[i]; if (flipped) { c = c == '0' ? '1' : '0'; }
			if (c != b[i] && p) { ok = false; break; }
			if (c != b[i]) { flipped ^= 1; }
			a[i] == '0' ? p++ : p--;
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}