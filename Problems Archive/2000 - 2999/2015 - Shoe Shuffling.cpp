#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (int& x : v) { cin >> x; }

		vector<int> idx(n); 

		//fills idx with 0, 1, 2, 3, ... i.e. idx[i] = i
		iota(idx.begin(), idx.end(), 0);

		auto comp = [&](const int& i, const int& j) {
			return v[i] < v[j];
		}; sort(idx.begin(), idx.end(), comp);

		int i = 0, j = 0; bool ok = true;
		vector<int> res(n);
		while (i != n) {
			while (j != n && v[idx[j]] == v[idx[i]]) { j++; }
			if (j - i == 1) { ok = false; break; }
			res[idx[i]] = idx[j - 1];
			for (int k = i + 1; k < j; k++)
				res[idx[k]] = idx[k - 1];
			i = j;
		}

		if (!ok) { cout << -1 << '\n'; continue; }
		for (int& x : res) cout << x + 1 << ' '; cout << '\n';
	}
}