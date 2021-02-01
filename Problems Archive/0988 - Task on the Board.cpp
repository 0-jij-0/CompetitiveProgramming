#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string s; vector<int> b;

inline vector<int> zeroIdx(vector<int> &b) {
	vector<int> res;
	for(int i = 0; i < (int)b.size(); i++)
		if (b[i] == 0) { b[i]--; res.push_back(i + 1); }
	return move(res);
}

int main() {
	int t; cin >> t;
	while (t--) {
		int m; cin >> s >> m; b.resize(m);
		for (auto &x : b) { cin >> x; }
		vector<int> freq(26, 0);
		for (char &c : s) { freq[c - 'a']++; }
		string res(m, '0'); vector<int> z = zeroIdx(b);
		for (int i = 25; i >= 0 && !z.empty(); i--) {
			if ((int)z.size() > freq[i]) { continue; }
			for (auto &x : z) { res[x - 1] = i + 'a'; }
			int l = 0, r = accumulate(z.begin(), z.end(), 0);
			int k = 0, n = (int)z.size(), lC = 0, rC = n;

			for (int j = 0; j < m; j++) {
				if (k < n && j + 1 == z[k]) { lC++; rC--; k++; l += j + 1; r -= j + 1; }
				if (b[j] < 0) { continue; }
				b[j] -= (lC * (j + 1) - l) + (r - rC * (j + 1));
			}
			z = zeroIdx(b);
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}