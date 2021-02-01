#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<vector<int>> v, ps; int n;

int maxSumSub(vector<int> &a) {
	int cur = 0, best = 0;
	for (auto &x : a) best = max(best, cur = max(0, cur += x));
	return best;
}

int maxSumMat() {
	int res = 0;
	for(int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			vector<int> a(n);
			for (int k = 0; k < n; k++) 
				if(i != 0) a[k] = ps[k][j] - ps[k][i - 1];
				else a[k] = ps[k][j];
			res = max(res, maxSumSub(a));
		}
	return res;
}

int main() {
	cin >> n; v.resize(n, vector<int>(n));
	for (auto &x : v) for (auto &y : x) cin >> y;
	ps.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		partial_sum(v[i].begin(), v[i].end(), ps[i].begin());
	cout << maxSumMat() << endl;
	cin.ignore(2); return 0;
}