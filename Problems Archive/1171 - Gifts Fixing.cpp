#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> a, b;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; a.resize(n); b.resize(n);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }
		int A = *min_element(a.begin(), a.end());
		int B = *min_element(b.begin(), b.end());
		ll res = 0; for (int i = 0; i < n; i++) {
			int x = a[i] - A, y = b[i] - B;
			res += min(x, y) + abs(x - y);
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}