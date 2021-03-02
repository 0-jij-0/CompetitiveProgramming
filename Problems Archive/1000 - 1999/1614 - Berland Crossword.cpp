#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, U, R, D, L; bool ok = false;
		cin >> n >> U >> R >> D >> L;

		for (int i = 0; i < 16; i++) {
			int u = U, r = R, d = D, l = L;
			if (i & 1) { l--; u--; }
			if (i & 2) { u--; r--; }
			if (i & 4) { r--; d--; }
			if (i & 8) { d--; l--; }
			if (max({ u, r, d, l }) > n - 2) { continue; }
			if (min({ u,r, d, l }) < 0) { continue; }
			ok = true; break;
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}