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
	freopen("stock.in", "r", stdin);

	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
		cout << y - x << '\n';
	}
}