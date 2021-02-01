#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

multiset<int> Y[10001];

int main() {
	int n; cin >> n; int res = 0;
	while (n--) { int x, y; cin >> x >> y; Y[x].insert(y); }
	int m; cin >> m; while (m--) {
		int x, y, r; cin >> x >> y >> r;
		for (int i = max(0, x - r); i <= min(10000, x + r); i++) {
			int dy = (int)floor(sqrt(r * r - (x - i) * (x - i)));
			Y[i].erase(Y[i].lower_bound(y - dy), Y[i].upper_bound(y + dy));
		}
	}
	for (int i = 0; i <= 10000; i++) res += Y[i].size();
	cout << res << '\n'; cin.ignore(2); return 0;
}