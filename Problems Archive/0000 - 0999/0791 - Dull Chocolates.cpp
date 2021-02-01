#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
typedef long long ll;

vector<vector<int>> v;

void find2DPref(int n, int m) {
	for (int i = 1; i < m; i++) { v[0][i] += v[0][i - 1]; }
	for (int i = 1; i < n; i++) { v[i][0] += v[i - 1][0]; }
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
}

int main() {
	ifstream ifs("dull.in");
	int t; ifs >> t;
	while (t--) {
		ll n, m; int k; ifs >> n >> m >> k;
		vector<pair<int, int>> p(k); vector<ll> X, Y;
		for (auto &x : p) { 
			ifs >> x.first >> x.second;
			X.push_back(x.first); Y.push_back(x.second);
		}
		sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
		sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
		v.clear(); v.resize(X.size(), vector<int>(Y.size(), 0));
		for (int i = 0; i < k; i++) {
			int x = lower_bound(X.begin(), X.end(), p[i].first) - X.begin();
			int y = lower_bound(Y.begin(), Y.end(), p[i].second) - Y.begin();
			v[x][y] = 1;
		}
		int a = (int)X.size(), b = (int)Y.size(); find2DPref(a, b);
		ll res = 0;
		for(int i = 0; i < a; i++)
			for (int j = 0; j < b; j++) {
				if (v[i][j] % 2 == 0) { continue; }
				if (i == a - 1 && j == b - 1) { res += (n - X[i] + 1)*(m - Y[j] + 1); continue; }
				if (i == a - 1) { res += (n - X[i] + 1)*(Y[j + 1] - Y[j]); continue; }
				if (j == b - 1) { res += (X[i + 1] - X[i])*(m - Y[j] + 1); continue; }
				res += (X[i + 1] - X[i])*(Y[j + 1] - Y[j]);
			}
		cout << res << ' ' << n * m - res << endl;
	}

	cin.ignore(2); return 0;
}