#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<bool>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k; 
	v.resize(n, vector<bool>(26, 0));

	for (auto& x : v) { 
		string s; cin >> s;
		for (char c : s) x[c - 'a'] = 1;
	}

	int res = 0;
	for (int i = 1; i < 1 << n; i++) {
		vector<int> freq(26, 0);
		for (int j = 0; j < n; j++) if (i & (1 << j)) {
			for (int c = 0; c < 26; c++) freq[c] += v[j][c];
		}
		int cur = count(freq.begin(), freq.end(), k);
		res = max(res, cur);
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}