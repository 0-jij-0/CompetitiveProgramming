#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n, X; cin >> n >> X; v.resize(n);
		for (auto& x : v) { cin >> x; }

		ll ma = 0; for (auto& x : v) ma += (x + X - 1) / X;
		ll mi = (accumulate(v.begin(), v.end(), 0ll) + X - 1) / X;

		cout << mi << ' ' << ma << '\n';
	}
	cin.ignore(2); return 0;
}