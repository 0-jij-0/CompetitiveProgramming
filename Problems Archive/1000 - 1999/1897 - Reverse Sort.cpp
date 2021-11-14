#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		int i = 0, j = n - 1; vector<int> res;
		while (i < j) {
			if (s[i] == '0') { i++; continue; }
			if (s[j] == '1') { j--; continue; }
			res.push_back(i++); res.push_back(j--);
		}
		if (res.empty()) { cout << 0 << '\n'; continue; }

		sort(res.begin(), res.end());
		cout << 1 << '\n' << res.size() << ' '; 
		for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}