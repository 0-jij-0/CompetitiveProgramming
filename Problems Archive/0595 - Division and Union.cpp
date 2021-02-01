#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<pair<int, int>> v;
vector<int> idx, res;

bool compare(const int &i1, const int &i2) { return v[i1] < v[i2]; }

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; 
		v.resize(n); idx.resize(n); res.resize(n);
		iota(idx.begin(), idx.end(), 0);
		for (auto &x : v) cin >> x.first >> x.second;
		sort(idx.begin(), idx.end(), compare);

		int max_right = v[idx[0]].second;
		res[idx[0]] = 1; bool b = false;
		for (int i = 1; i < n; i++) {
			if (v[idx[i]].first <= max_right) {
				max_right = max(max_right, v[idx[i]].second);
				res[idx[i]] = 1; continue;
			}
			while (i < n) { res[idx[i++]] = 2; }
			b = true; break;
		}
		if (!b) { cout << -1 << endl; continue; }
		for (auto &x : res) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}