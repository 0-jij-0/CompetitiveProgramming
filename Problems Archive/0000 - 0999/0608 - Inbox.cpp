#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int res = 0, i = 0, j = 0;
	while (j < n) {
		if (!v[i]) { i = j = j + 1; continue; }
		if (v[j]) { j++; continue; }
		res += j - i + 1; i = j;
	}
	v.back() ? res += j - i : res--;
	cout << max(res, 0) << endl;
	cin.ignore(2); return 0;
}