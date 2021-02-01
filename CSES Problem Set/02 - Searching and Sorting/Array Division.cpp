#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v; int n, k;

bool check(ll m) {
	ll sum = 0; int s = 0;
	for (auto &x : v) {
		if (x > m) { return false; }
		sum += x; if (sum > m) { s++; sum = x; }
	}
	return s < k;
}

ll findMinMaxSum() {
	ll l = 0, r = 1ll << 60;
	while (l != r) {
		ll mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	cin >> n >> k; v.resize(n);
	for (auto &x : v) { cin >> x; }
	cout << findMinMaxSum() << endl;
	cin.ignore(2); return 0;
}