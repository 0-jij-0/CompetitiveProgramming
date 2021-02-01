#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

string s;
vector<int> v, b;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; v.clear(); b.clear();
		v.resize(n, 0); b.resize(n, 1);
		for (int i = 0; i < n - 1; i++)
			v[i] = (s[i] == s[i + 1]);

		int i = 0, j = 0, res = 0;
		while (i < n) {
			if (!b[i]) { i++; continue; }
			res++; if (i == n - 1) { break; }

			if (v[i]) {
				i++; j++; while (i < n && v[i - 1]) {
					b[i - 1] = v[i - 1] = 0; i++; j++;
				}
				continue;
			}
			b[i] = v[i] = 0;
			while (j < n && !v[j]) { j++; }
			if (j < n) { b[j] = v[j] = 0; i++; }
			else {
				i++; while (i < n && !b[i]) { i++; }
				i++;
			}
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}