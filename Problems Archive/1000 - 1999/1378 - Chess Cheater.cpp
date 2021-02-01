#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k >> s;
		int pref = 0, suf = 0, score = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') { continue; }
			if (i && s[i - 1] == 'W') { score += 2; continue; }
			score++;
		}

		while (pref < n && s[pref] == 'L') { pref++; }
		while (suf < n && s[n - 1 - suf] == 'L') { suf++; }

		if (pref == n) { cout << max(0, 2 * k - 1) << '\n'; continue; }

		vector<int> v; int i = pref, j = i; while (j != n) {
			if (s[i] == 'W') { i++; j++; continue; }
			if (s[j] == 'L') { j++; continue; }
			v.push_back(j - i); i = j = j + 1;
		}
		sort(v.begin(), v.end());
		for (auto &x : v) {
			if (k < x) { score += 2 * k; k = 0; break; }
			k -= x; score += 2 * x + 1;
		}
		if (k < pref) { score += 2 * k; k = 0; }
		else { score += 2 * pref; k -= pref; }
		if (k < suf) { score += 2 * k; }
		else { score += 2 * suf; }
		cout << score << '\n';
	}
	cin.ignore(2); return 0;
}