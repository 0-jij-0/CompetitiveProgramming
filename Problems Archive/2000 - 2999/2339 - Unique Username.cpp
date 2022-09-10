#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

vector<string> S; int n;
set<string> T; string res;
bool ok = false;

void generate(string cur, int i, int und) {
	if (ok) return;

	if (i == n - 1) {
		cur += S[i];
		if (cur.size() < 3 || T.count(cur)) { return; }
		ok = true; res = cur; return;
	}
	
	for (int j = 1; j <= und - (n - i - 2); j++)
		generate(cur + S[i] + string(j, '_'), i + 1, und - j);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m; cin >> n >> m; S.resize(n); int totalSize = 0;
	for (auto& x : S) { cin >> x; totalSize += x.size(); }
	while (m--) { string t; cin >> t; T.insert(t); }

	sort(S.begin(), S.end());
	do { generate("", 0, 16 - totalSize); }
	while (!ok && next_permutation(S.begin(), S.end()));

	cout << (ok ? res : "-1") << '\n';
}