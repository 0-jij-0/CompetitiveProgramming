#include <iostream>
#include <vector>
using namespace std;

vector<int> P;

struct FT {
	int n; vector<int> vals;
	FT(int n) : n(n), vals(n + 1, 0) {}

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; P.resize(n);
	for (auto& x : P) cin >> x;

	FT ft(n + 1); for (auto& x : P) {
		cout << ft.query(x + 1, n) << '\n';
		ft.update(x, 1);
	}

}