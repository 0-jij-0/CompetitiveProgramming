#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; x--; }
		vector<int> pmi(n, v[0]), pma(n, v[0]), vismi(n, 0); 
		vector<int> visma(n); iota(visma.begin(), visma.end(), 0);
		int l = 0, r = v[0] - 1; vismi[v[0]] = 1; visma[v[0]] = v[0] - 1;

		for (int i = 1; i < n; i++) {
			if (v[i] != v[i - 1]) { pmi[i] = v[i]; vismi[v[i]] = 1; continue; }
			while (vismi[l]) l++; pmi[i] = l; vismi[l] = 1;
		}

		for (int i = 1; i < n; i++) {
			if (v[i] != v[i - 1]) { pma[i] = v[i]; visma[v[i]] = r = v[i] - 1; continue; }
			int prev = r; while (visma[r] != r) { r = visma[r]; }
			visma[prev] = r - 1; pma[i] = r; visma[r] = r - 1;
		}

		for (auto& x : pmi) cout << x + 1 << ' '; cout << '\n';
		for (auto& x : pma) cout << x + 1 << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}