#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;
		ll sum = accumulate(v.begin(), v.end(), 0ll) % n;
		cout << sum * (n - sum) << '\n';
	}
}