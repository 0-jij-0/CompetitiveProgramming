#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		vector<int> p(k); iota(p.begin(), p.end(), 1);
		reverse(p.begin() + (k - (n - k) - 1), p.end());
		for (auto& x : p) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}