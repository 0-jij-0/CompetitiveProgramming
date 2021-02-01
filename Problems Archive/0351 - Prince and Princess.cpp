#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> b, w, ind;

int LIS(vector<int> &v) {
	vector<int> res(v.size() + 1, INT_MAX);	res[0] = INT_MIN;
	for (auto &x : v) { *upper_bound(res.begin(), res.end(), x) = x; }
	return find(res.begin(), res.end(), INT_MAX) - res.begin() - 1;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, p, q; cin >> n >> p >> q;
		b.clear(); w.clear(); ind.clear();
		p++; q++; b.resize(p); w.resize(q);
		ind.resize(n*n + 1, -1);
		for (auto &x : b) { cin >> x; }
		for (auto &x : w) { cin >> x; }
		if (p < q) { swap(p, q); swap(b, w); }
		for (int j = 0; j < p; j++) { ind[b[j]] = j; }
		vector<int> w_temp;
		for (int j = 0; j < q; j++) {
			if (ind[w[j]] == -1) { continue; }
			w_temp.push_back(ind[w[j]]);
		}
		w = move(w_temp);
		cout << "Case " << i + 1 << ": " << LIS(w) << endl;
	}
	cin.ignore(2); return 0;
}