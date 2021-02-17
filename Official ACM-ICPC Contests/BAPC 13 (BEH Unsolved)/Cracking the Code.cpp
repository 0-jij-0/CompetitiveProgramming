#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
vector<int> ENC;

bool check(string &e, string &d) {
	if (e.size() != d.size()) { return false; }
	int n = (int)e.size();

	set<int> unused1, unused2;
	for (int i = 0; i < 26; i++) { unused1.insert(i); unused2.insert(i); }

	for (int i = 0; i < n; i++) {
		if (ENC[d[i] - 'a'] == -1) { ENC[d[i] - 'a'] = e[i] - 'a'; continue; }
		if ((e[i] - 'a') != ENC[d[i] - 'a']) { return false; }
	}

	for (int i = 0; i < 26; i++) {
		if (ENC[i] == -1) { continue; }
		for (int j = i + 1; j < 26; j++) {
			if (ENC[j] == -1) { continue; }
			if (ENC[i] == ENC[j]) { return false; }
		}

		unused1.erase(i); unused2.erase(ENC[i]);
	}

	if (unused1.size() == 1) {
		int last1 = *unused1.begin();
		int last2 = *unused2.begin();
		ENC[last1] = last2;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		v.clear(); ENC.clear(); ENC.resize(26, -1);
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		string D, X; cin >> D >> X;
		vector<vector<int>> res;

		for (int i = 0; i < n; i++) {
			fill(ENC.begin(), ENC.end(), -1);
			if (check(v[i], D)) { res.push_back(ENC); }
		}
		if (res.empty()) { cout << "IMPOSSIBLE" << '\n'; continue; }

		fill(ENC.begin(), ENC.end(), -1); n = (int)res.size();
		for (int i = 0; i < 26; i++) {
			bool ok = true;
			for (int j = 1; j < n; j++)
				if (res[j][i] != res[0][i]) { ok = false; break; }
			if (ok) { ENC[i] = res[0][i]; }
		}

		vector<int> DEC(26, -1);
		for (int i = 0; i < 26; i++) if (ENC[i] != -1) { DEC[ENC[i]] = i; }
		for (auto &x : X) { cout << ((DEC[x - 'a'] == -1) ? '?' : (char)(DEC[x - 'a'] + 'a')); }
		cout << '\n';
	}
}