#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q >> s;
	int rot = 0; while (q--) {
		int t, x; cin >> t >> x; x--;
		if (t == 1) { rot = (rot + x + 1) % n; continue; }
		if (x < rot) cout << s[x + n - rot] << '\n';
		else cout << s[x - rot] << '\n';
	}
}