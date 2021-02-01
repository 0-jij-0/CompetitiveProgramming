#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool check(int d, int m, int n) {
	long long res = 0;
	for (int i = 0; i < n; i++) 
		res += max(0, v[i] - i / d);
	return res >= m;
}

int find_min_days(int n, int m) {
	int l = 1, r = n + 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check(mid, m, n);
		b ? r = mid : l = mid + 1;
	}
	return l == n + 1 ? -1 : l;
}

int main() {
	int n, m; cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.rbegin(), v.rend());

	cout << find_min_days(n, m) << endl;
	cin.ignore(2); return 0;
}