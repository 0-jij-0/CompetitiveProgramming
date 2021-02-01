#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g, pref;
int n, k;

int main() {
	cin >> n >> k; g.resize(n); pref.resize(n); int white = 0;
	for (int i = 0; i < n; i++) { g[i].resize(n); pref[i].resize(n, 0); }
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c; cin >> c; g[i][j] = (c == 'B');
			if (c == 'W') { white++; }
		}
	for (int i = 0; i < n; i++) {
		pref[i][0] = g[i][0];
		for (int j = 1; j < n; j++) {
			pref[i][j] = pref[i][j - 1] + g[i][j];
		}
	}
	int maxi = 0;
	for (int j = 0; j < n - k; j++) {
		int m = 0;
		for (int i = 0; i < k; i++)
			m += pref[i][j + k - 1] - pref[i][j] + g[i][j];
		maxi = max(m, maxi);
		for (int i = k; i < n - k; i++) {
			m -= pref[i - k][j + k - 1] - pref[i - k][j] + g[i - k][j];
			m += pref[i][j + k - 1] - pref[i][j] + g[i][j];
			maxi = max(m, maxi);
		}
	}
	cout << maxi + white << endl;
	cin.ignore(2); return 0;
}