#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

string s;

void add(int i, vector<int>& freq, int& mask, int& odd) {
	freq[i]++; if (freq[i] == 1) { mask |= 1 << i; }
	freq[i] & 1 ? odd++ : odd--;
}

int main() {
	freopen("substr.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q >> s;
		set<pair<int, int>> res;
		for (int i = 0; i < n; i++) {
			vector<int> freq(26); int mask = 0, odd = 0;
			for (int j = i; j < n; j++) {
				add(s[j] - 'a', freq, mask, odd);
				if (odd < 2) res.insert({ mask, j - i + 1 });
			}
		}
		while (q--) {
			int k, mask = 0; string p; cin >> k >> p;
			for (char c : p) mask |= (1 << (c - 'a'));
			cout << (res.count({mask, k}) ? "YES" : "NO") << '\n';
		}
	}
}