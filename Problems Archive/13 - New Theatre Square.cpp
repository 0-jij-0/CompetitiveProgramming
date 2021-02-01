#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, x, y; cin >> n >> m >> x >> y;
		v.resize(n); for (auto &s : v) { cin >> s; }
		
		int res = 0; for (auto &s : v) {
			int i = 0, j = 0;
			while (j != m) {
				if (s[i] == '*') { i = j = j + 1; continue; }
				if (s[j] == '.') { j++; continue; }
				int d = j - i; res += min(2 * x, y)*(d / 2) + x * (d % 2);
				i = j = j + 1;
			}
			int d = j - i; res += min(2 * x, y)*(d / 2) + x * (d % 2);
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}