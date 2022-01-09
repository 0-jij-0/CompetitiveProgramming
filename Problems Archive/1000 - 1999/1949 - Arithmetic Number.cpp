#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

ll arithmetic(int n, int f, int r) {
	ll res = 0; int cur = f, len = 0;
	while (len != n) {
		if (cur > 9 || cur < 0) { return -1; }
		res = res * 10 + cur; 
		len++; cur += r; 
	}
	return res;
}

int main() {
	for (int n = 1; n < 19; n++)
		for (int f = 1; f < 10; f++)
			for (int r = -8; r < 9; r++)
				v.push_back(arithmetic(n, f, r));

	sort(v.begin(), v.end()); ll x; cin >> x;
	cout << *lower_bound(v.begin(), v.end(), x) << '\n';
	cin.ignore(2); return 0;
}