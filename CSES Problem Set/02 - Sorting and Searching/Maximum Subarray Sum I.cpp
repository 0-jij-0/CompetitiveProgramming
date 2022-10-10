#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	ll cur = 0, res = v[0];
	for (auto &x : v) {
		cur += x; res = max(res, cur);
		if (cur < 0) { cur = 0; }
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}