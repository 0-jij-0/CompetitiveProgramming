#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<vector<int>> v, ps; int n;

int maxSumSub(vector<int> &a) {
	int cur = 0, best = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i]; sum += a[i]; 
		a[i] = -a[i]; best = max(best, cur);
		if (cur < 0) { cur = 0; }
	}
	int curr = 0, bestt = 0;
	for (int i = 0; i < n; i++) {
		curr += a[i]; bestt = max(bestt, curr);
		if (curr < 0) { curr = 0; }
	}
	return max(best, sum + bestt);
}

int maxSumMat() {
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			vector<int> a1(n), a2(n);
			for (int k = 0; k < n; k++) {
				if (i == 0) a1[k] = ps[k][j];
				else { a1[k] = ps[k][j] - ps[k][i - 1]; }
				a2[k] = ps[k].back() - a1[k];
			}
			res = max({ res, maxSumSub(a1), maxSumSub(a2) });
		}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n; v.clear(); v.resize(n, vector<int>(n));
		for (auto &x : v) for (auto &y : x) cin >> y;
		ps.clear(); ps.resize(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			partial_sum(v[i].begin(), v[i].end(), ps[i].begin());
		cout << maxSumMat() << endl;
	}
	cin.ignore(2); return 0;
}