#include <iostream>
#include <vector>
using namespace std;

struct FT {
	int n; vector<int> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) vals[i] += x;
	}

	int query(int i) { // sum from 0 ... i
		int sum = 0;
		for (++i; i; i -= i & -i) sum += vals[i];
		return sum;
	}
	int query(int i, int j) { return query(j) - query(i - 1); }
};

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; A.resize(n << 1);
	for (auto& x : A) cin >> x;

	FT ft(n << 1); vector<int> idx(n, -1), res(n);
	for (int i = 0; i < n << 1; i++) {
		if (idx[--A[i]] == -1) { idx[A[i]] = i; ft.update(i, 1); continue; }
		ft.update(idx[A[i]], -2); ft.update(i, 1);
		res[A[i]] = ft.query(idx[A[i]] + 1, i - 1);
	}

	for (auto& x : res) cout << x << ' '; cout << '\n';
}