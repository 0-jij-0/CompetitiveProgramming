#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; int n;

int closestToTheLeft(int x) {
	int l = -1, r = n - 1;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		v[mid] >= x ? r = mid - 1 : l = mid;
	}
	return l + 1;
}

int closestToTheRight(int x) {
	int l = 0, r = n;
	while (l != r) {
		int mid = (l + r) >> 1;
		v[mid] <= x ? l = mid + 1 : r = mid;
	}
	return l + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; v.resize(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	int k; cin >> k; while (k--) {
		int l, r; cin >> l >> r;
		int L = closestToTheLeft(l);
		int R = closestToTheRight(r);
		cout << R - L - 1 << '\n';
	}
}