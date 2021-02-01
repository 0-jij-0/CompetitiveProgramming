#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> res;

bool fill_res(int n, int k) {
	int low = 1, high = n;
	while (n != 0 || k != 0) {
		double w = pow(2.0, k + 0.0) - 1.0;
		double a = (n + 0.0) / w;
		double b = ((n + 0.0) / (k + 0.0)) - ((k - 1.0) / 2.0);
		if (floor(a) == a || floor(b) == b) { goto HERE; }
		if (floor(a) >= floor(b)) { return false; }

	HERE: int from = (int)ceil(a); int to = (int)floor(b);
		from = (from < low) ? low : from;
		to = (to < high) ? to : high;
		if (from > to) { return false; }
		res.push_back(from);
		n -= from; k--; low = from + 1; high = 2 * from;
	}
	return true;
}

int main() {
	int n, k; cin >> n >> k;
	bool b = fill_res(n, k);
	if (!b) { cout << "NO" << endl; return 0; }
	cout << "YES" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i + 1 != res.size()) { cout << " "; }
	}
	cout << endl;
	return 0;
}

