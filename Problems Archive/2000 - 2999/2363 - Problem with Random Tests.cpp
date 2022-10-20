#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n >> s;
	int first1 = find(s.begin(), s.end(), '1') - s.begin();
	if (first1 == n) { cout << "0\n"; return 0; }

	string res = s.substr(first1);
	int first0 = find(s.begin() + first1, s.end(), '0') - s.begin();
	if (first0 == n) { cout << res << '\n'; return 0; }

	int bits = n - first0; vector<int> cand;
	for (int i = 0; i < first0; i++)
		if (s[i] == '1') cand.push_back(i);

	res[first0 - first1] = '1';
	for (int j = first0 + 1; j < n; j++) {
		if (s[j] == '1') continue;

		vector<int> newCand; for (auto& x : cand) {
			if (s[x + (j - first0)] == '1') newCand.push_back(x);
		}

		if (newCand.empty()) { continue; }
		cand = move(newCand); res[j - first1] = '1';
	}

	cout << res << '\n';

}