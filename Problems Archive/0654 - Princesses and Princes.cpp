#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> princes;
vector<bool> princesses;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) {
			int k; cin >> k; x.resize(k);
			for (auto &y : x) { cin >> y; y--; }
		}
		princes.clear(); princes.resize(n, -1);
		princesses.clear(); princesses.resize(n, false);
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < (int) v[i].size(); j++)
				if (princes[v[i][j]] == -1) {
					princes[v[i][j]] = i;
					princesses[i] = true;
					break;
				}
		}
		bool impr = false; int ps = 0, p = 0;
		for (int i = 0; i < n; i++) {
			if (!princesses[i]) { ps = i; impr = true; break; }
		}
		for (int j = 0; j < n; j++) {
			if (princes[j] == -1) { p = j; break; }
		}

		if (impr) { cout << "IMPROVE" << endl << ps + 1 << ' ' << p + 1 << endl; }
		else { cout << "OPTIMAL" << endl; }

	}
	cin.ignore(2); return 0;
}