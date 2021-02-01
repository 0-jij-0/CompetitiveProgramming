#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n; vector<int> v(n);
	for (auto &x : v) { cin >> x; }

	for (int i = 0; i < n; i++)
		v.push_back(v[i]);

	int l = 0, r = 0, res = 0;
	while (r < 2 * n) {
		if (!v[r]) { l = r; l++; r++; continue; }
		if (r - l + 1 > res) { res = r - l + 1; }
		r++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}