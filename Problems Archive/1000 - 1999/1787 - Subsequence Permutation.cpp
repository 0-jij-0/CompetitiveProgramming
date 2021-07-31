#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s, t;

int main() {
	int T; cin >> T; while (T--) {
		int n; cin >> n >> s; t = s;
		sort(t.begin(), t.end());

		int res = 0; for (int i = 0; i < n; i++)
			res += t[i] != s[i];

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}