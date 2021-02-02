#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("mosalah.in", "r", stdin);
 
	int t; cin >> t;
	while (t--) {
		int n, m, x, y; cin >> n >> m >> x >> y;
		int target = n * (x + y); target -= m;
		if (y == 0 && target > 0) { cout << -1 << '\n'; }
		else { cout << max(target, 0) << '\n'; }
	}
}