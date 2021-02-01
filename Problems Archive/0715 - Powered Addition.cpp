#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;

vector<ll> v;

int numBits(int n) {
	string res = "";
	while (n) { res.push_back('0' + (n % 2)); n >>= 1; }
	return (int)res.size();
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		adjacent_difference(v.begin(), v.end(), v.begin());
		int res = 0;
		for (int i = 1; i < n; i++) {
			if (v[i] >= 0) { continue; }
			res = max(res, numBits(-v[i]));
			if (i + 1 < n) { v[i + 1] += v[i]; }
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}