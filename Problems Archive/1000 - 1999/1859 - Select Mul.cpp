#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	string s; cin >> s; int n = (int)s.size();
	sort(s.begin(), s.end()); ll res = 0; do {
		if (s[0] == '0') { continue; }
		for (int i = 1; i < n; i++) {
			if (s[i] == '0') { continue; }
			ll L = stoi(s.substr(0, i));
			ll R = stoi(s.substr(i));
			res = max(res, L * R);
		}
	} while (next_permutation(s.begin(), s.end()));

	cout << res << '\n';
	cin.ignore(2); return 0;
}