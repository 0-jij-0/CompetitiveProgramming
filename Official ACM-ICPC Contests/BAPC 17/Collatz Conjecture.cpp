#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) { swap(a, b); }
	return b ? gcd(b, a % b) : a;
}

set<long long> res, cur[2];
vector<long long> v;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	bool now = true;
	for (int i = n - 1; i >= 0; i--) {
		cur[now].clear(); cur[!now].insert(v[i]);
		for (auto &x : cur[!now])
			cur[now].insert(gcd(v[i], x));
		res.insert(cur[now].begin(), cur[now].end());
		now = !now;
	}
	cout << (int) res.size() << endl;
	cin.ignore(2); return 0;
}