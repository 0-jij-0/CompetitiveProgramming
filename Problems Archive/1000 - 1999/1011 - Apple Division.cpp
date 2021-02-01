#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	ll sum = accumulate(v.begin(), v.end(), 0ll);
	ll ans = 0, cur;
	for (int i = 0; i < 1 << n; i++) { 
		cur = 0; for (int j = 0; j < n; j++)
			if (i >> j & 1)	cur += v[j];
		if (cur <= sum / 2) { ans = max(ans, cur); }
	}
	cout << sum - 2 * ans << endl;
	cin.ignore(2); return 0;
}