#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<int> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	int query(int i) const { // sum from 0 ... i
		int sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	int query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto comp = [&](const int& i, const int& j) {
		return v[i] < v[j];
	};

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		
		vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), comp);

		FT ft(n); ll res = 0; int i = 0, j = 0;
		while (i != n) {
			while (j != n && v[idx[j]] == v[idx[i]]) { j++; }
			for (int k = i; k < j; k++)
				if (v[idx[k]] < (idx[k] + 1))
					res += ft.query(v[idx[k]] - 1);

			for (int k = i; k < j; k++)
				if (v[idx[k]] < (idx[k] + 1))
					ft.update(idx[k] + 1, 1);
			i = j;
		}
		cout << res << '\n';
	}
}