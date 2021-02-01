#include <iostream>
#include <vector>
using namespace std;
const int SZ = 30;

vector<int> anc[SZ];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 0; i < SZ; i++) { anc[i].resize(n); }
	for (int i = 0; i < n; i++) { 
		cin >> anc[0][i]; anc[0][i]--;
	}
	for (int i = 1; i < SZ; i++)
		for (int u = 0; u < n; u++)
			anc[i][u] = anc[i - 1][anc[i - 1][u]];

	while (q--) {
		int v, k; cin >> v >> k; v--;
		int p = SZ - 1; while (k) {
			if ((1 << p) > k) { p--; continue; }
			k -= (1 << p); v = anc[p][v];
		}
		cout << v + 1 << '\n';
	}
	cin.ignore(2); return 0;
}