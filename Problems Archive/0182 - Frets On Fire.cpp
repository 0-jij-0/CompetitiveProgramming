#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v, dif, pref;
int n, q;

void precomp() {
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end()); n = (int)v.size();
	dif.resize(n - 1); pref.resize(n);
	for (int i = 0; i < n - 1; i++) { dif[i] = v[i + 1] - v[i]; }
	sort(dif.begin(), dif.end()); pref[0] = 0ll;
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + dif[i - 1];
	}
}

long long query(long long range) {
	long long res = 0;
	auto it = lower_bound(dif.begin(), dif.end(), range);
	int idx1 = it - dif.begin();
	res += pref[idx1];
	long long idx2 = n - idx1;
	res += range * idx2;
	return res;
}


int main() {
	cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	precomp(); n = v.size();
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long l, r; cin >> l >> r;
		cout << query(r - l + 1);
		if (i + 1 != q) { cout << ' '; }
		else { cout << endl; }
	}

	cin.ignore(2); return 0;
}