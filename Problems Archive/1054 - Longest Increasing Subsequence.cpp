#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, res;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	res.resize(n + 1, 1 << 30); res[0] = -res[0];
	for (auto &x : v) { *lower_bound(res.begin(), res.end(), x) = x; }
	cout << find(res.begin(), res.end(), 1 << 30) - res.begin() - 1 << endl;
	cin.ignore(2); return 0;
}