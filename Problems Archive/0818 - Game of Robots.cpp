#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;
vector<int> ids;

int main() {
	v.resize(70000); iota(v.begin(), v.end(), 1ll);
	partial_sum(v.begin(), v.end(), v.begin());
	int n; ll k; cin >> n >> k; ids.resize(n);
	for (auto &x : ids) { cin >> x; }

	int idx = lower_bound(v.begin(), v.end(), k) - v.begin();
	cout << (v[idx] == k ? ids[idx] : ids[k - v[idx - 1] - 1]) << endl;
	cin.ignore(2); return 0;
}