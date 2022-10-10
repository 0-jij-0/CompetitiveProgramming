#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s; int n = (int)s.size();
	int i = 0, j = 0, res = 0;
	while (j != n) {
		if (s[j] == s[i]) { j++; continue; }
		res = max(res, j - i); i = j;
	}
	cout << max(res, j - i) << '\n';
}