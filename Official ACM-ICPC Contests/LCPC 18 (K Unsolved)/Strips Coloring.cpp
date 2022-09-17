#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;

int main() {
	freopen("strips.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k >> s;

		vector<int> zerosEdge, zeros;
		int res = 0, cur = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) { cur++; continue; }
			if (s[i] == '0') { res++; cur = 1; continue; }
			(cur == i ? zerosEdge : zeros).push_back(cur);
		}
		if (s.back() == '0') { zerosEdge.push_back(cur); }

		sort(zerosEdge.begin(), zerosEdge.end());
		sort(zeros.begin(), zeros.end());

		int ans = res, ZE = (int)zerosEdge.size(), Z = (int)zeros.size();
		for (int m = 0; m <= ZE; m++) {
			int curRes = ans - m, rem = k;

			for (int i = 0; i < m; i++) { rem -= zerosEdge[i]; }
			if (rem < 0) { continue; }

			for (int i = 0; i < Z; i++) {
				if (rem < zeros[i]) { break; }
				rem -= zeros[i]; curRes -= 2;
			}
			res = min(res, curRes);
		}
		cout << max(res, 0) << '\n';
	}
	
	cin.ignore(2); return 0;
}