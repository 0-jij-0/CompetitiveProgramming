#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s; int n = (int)s.size(); v.resize(n);
		for (int i = 0; i < n; i++) v[i] = s[i] - '0';

		vector<int> idx[9];
		partial_sum(v.begin(), v.end(), v.begin());
		int w, m; cin >> w >> m; idx[v[w - 1] % 9].push_back(0);
		for (int i = w; i < n; i++) idx[(v[i] - v[i - w]) % 9].push_back(i - w + 1);
		
		while (m--) {
			int L, R, K; cin >> L >> R >> K;
			int S = (v[--R] - (--L ? v[L - 1] : 0)) % 9;

			int L1 = -2, L2 = -2;
			for (int i = 0; i < 9; i++) if(!idx[i].empty()) {
				int req = (K - (i * S) % 9 + 9) % 9;
				if (idx[req].empty() || (req == i && idx[i].size() == 1)) { continue; }
				if (L1 == -2 || idx[i][0] < L1) { L1 = idx[i][0]; L2 = idx[req][req == i]; continue; }
			}

			cout << L1 + 1 << ' ' << L2 + 1 << '\n';
		}
	}
}