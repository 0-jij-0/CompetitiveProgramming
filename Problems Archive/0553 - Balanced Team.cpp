#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());

	int l = 0, r = 0, res = 0;
	while (r < n) {
		if (v[r] - v[l] > 5) { l++; continue; }
		if (r - l + 1 > res) { res = r - l + 1; }
		r++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}