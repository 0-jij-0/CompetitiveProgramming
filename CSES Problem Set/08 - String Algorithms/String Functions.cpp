#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> ZAlgo(string& s) {
	int n = s.size();
	vector<int> z(n, 0);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R - L] == s[R]) { R++; }
			z[i] = R - L; R--;
		}
		else {
			int k = i - L;
			if (z[k] < R - i + 1) { z[i] = z[k]; continue; }
			L = i;
			while (R < n && s[R - L] == s[R]) { R++; }
			z[i] = R - L; R--;
		}
	}
	return move(z);
}

vector<int> prefixFunction(string& s) {
	vector<int> pf(s.size(), 0);
	for (int i = 1; i < s.size(); i++) {
		int j = pf[i - 1];
		while (j > 0 && s[j] != s[i]) { j = pf[j - 1]; }
		if (s[j] == s[i]) { j++; }
		pf[i] = j;
	}
	return move(pf);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;
	vector<int> Z = ZAlgo(s), P = prefixFunction(s);
	for (auto &x : Z) cout << x << ' '; cout << '\n';
	for (auto &x : P) cout << x << ' '; cout << '\n';
}