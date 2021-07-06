#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef double ld;

vector<ld> E;
vector<int> v, idx;

int main() {
	freopen("dimension35c.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		E.clear(); v.clear(); idx.clear();
		int n; cin >> n; E.resize(n, 0.0); v.resize(n);
		for (auto &x : v) { cin >> x; }
		idx.resize(n); iota(idx.begin(), idx.end(), 0);
		auto comp = [&](const int &i, const int &j) { return v[i] < v[j]; };
		sort(idx.begin(), idx.end(), comp);

		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				E[idx[i]] += (v[idx[j]] + 0.0) / (abs(j - i) + 1.0);
			}

		for (int i = 0; i < n; i++) v[idx[i]] = idx[i];
		cout << fixed << setprecision(6);
		for (int i = 0; i < n; i++) cout << E[v[i]] << ' ';
		cout << '\n';
	}
}