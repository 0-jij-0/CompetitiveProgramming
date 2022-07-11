#include <iostream>
#include <string>
using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s >> t; bool ok = true;
	int iS = 0, jS = 0, n = (int)s.size();
	int iT = 0, jT = 0, m = (int)t.size();

	while (iS != n && jS != m) {
		while (jS != n && s[iS] == s[jS]) { jS++; }
		while (jT != m && t[iT] == t[jT]) { jT++; }

		int lenS = jS - iS, lenT = jT - iT;
		if (s[iS] != t[iT]) { ok = false; break; }
		if (lenS > lenT) { ok = false; break; }
		if (lenS != lenT && lenS == 1) { ok = false; break; }
		iS = jS; iT = jT;
	}

	cout << (ok && iS == n && iT == m ? "Yes" : "No") << '\n';
}