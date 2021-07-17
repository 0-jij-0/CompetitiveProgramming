#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("phantom.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		cout << max(0, n - m) << '\n';
	}

	cin.ignore(2); return 0;
}