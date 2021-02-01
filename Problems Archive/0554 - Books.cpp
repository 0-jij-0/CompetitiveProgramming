#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n, t; cin >> n >> t; v.resize(n);
	for (auto &x : v) { cin >> x; }

	int l = 0, r = 0, sum = 0, res = 0;
	while (r < n) {
		sum += v[r];
		while (sum > t) { sum -= v[l]; l++; continue; }
		if (r - l + 1 > res) { res = r - l + 1; }
		r++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}