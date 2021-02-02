#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
#include <bitset>
using namespace std;

int variableCount(const string& a, const string& b) {
	string c = a + b; sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	return c.size();
}

bool check(const string& p, const string &a, const string &b) {
	vector<int> m(26, -1); int j = 0, A = 0, B = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		int c = a[i] - 'a'; if (m[c] == -1) { m[c] = p[j++] - '0'; }
		A = A * 10 + m[c];
		if (i == 0 && m[c] == 0) { return 0; }
	}
	for (int i = 0; i < (int)b.size(); i++) {
		int c = b[i] - 'a'; if (m[c] == -1) { m[c] = p[j++] - '0'; }
		B = B * 10 + m[c];
		if (i == 0 && m[c] == 0) { return 0; }
	}
	return A < B;
}

int main() {
	freopen("inequality.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string a, b; cin >> a >> b; int n = variableCount(a, b);
		if (n > 10) { cout << 0 << '\n'; continue; }

		int set = (1 << n) - 1, limit = (1 << 10), res = 0;
		string P = "0123456789"; while (set < limit) {
			string p; for (int i = 0; i < 10; i++)
				if (set & (1 << i)) p.push_back(P[i]);

			do { res += check(p, a, b); } while (next_permutation(p.begin(), p.end()));

			int c = set & -set, r = set + c;
			set = (((r ^ set) >> 2) / c) | r;
		}

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}