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

	FT ft(n << 1); vector<int> res(n, -1);
	for (int i = 0; i < n << 1; i++) {
		if (res[--A[i]] == -1) { res[A[i]] = i; continue; }
		ft.update(res[A[i]], 1);
		res[A[i]] = ft.query(res[A[i]] + 1, (n << 1) - 1);
	}

	for (auto& x : res) cout << x << ' '; cout << '\n';
}