#include <iostream>
#include <vector>
using namespace std;

string toBinary(int n) {
	string res = "";
	while (n) { res.push_back('0' + (n & 1)); n >>= 1; }
	return res;
}

vector<pair<int, int>> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int n; cin >> n;
		if (n < 100) {
			cout << "Case #" << t << ": " << '\n';
			for (int i = 1; i <= n; i++) { cout << i << ' ' << 1 << '\n'; }
			continue;
		}
		string s = toBinary(n - 30); res.clear(); int r = 1; bool b = true;
		while (r <= (int)s.size()) {
			if (s[r - 1] - '0') {
				if (b) { for (int i = 1; i <= r; i++) { res.push_back({ r, i }); } }
				else { for (int i = r; i > 0; i--) { res.push_back({ r, i }); } }
				n -= 1 << (r - 1); b = !b; r++; continue;
			}
			n--; res.push_back({ r, (b ? 1 : r) }); r++;
		}
		while (n) { res.push_back({ r, (b ? 1 : r) }); r++; n--; }

		cout << "Case #" << t << ": " << '\n';
		for (auto &x : res) { cout << x.first << ' ' << x.second << '\n'; }	
	}
	cin.ignore(2); return 0;
}
