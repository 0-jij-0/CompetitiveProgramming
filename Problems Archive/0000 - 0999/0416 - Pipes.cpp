#include <iostream>
#include <string>
using namespace std;

string str[2];

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		cin >> str[0] >> str[1];
		bool s = false, res = true; int r = 0;
		for (int i = 0; i < n; i++) {
			if (str[r][i] < '3' && !s) { continue; }
			if (str[r][i] < '3') { res = false; break; }
			if (!s) { r = (r + 1) % 2; i--; s = !s; continue; }
			s = !s;
		}
		if (res && r) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}