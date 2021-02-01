#include <iostream>
#include <vector>
using namespace std;

vector<int> v; int n, m;

int opNum(int from, int to) {
	if (to >= from) { return to - from; }
	return m + (to - from);
}

bool check(int k) {
	int prev = 0, n = (int)v.size();
	for (int i = 0; i < n; i++) {
		int x = opNum(v[i], prev);
		if (x > k && prev > v[i]) { return false; }
		if (x > k && prev < v[i]) { prev = v[i]; continue; }
	}
	return true;
}

int findMin() {
	int l = 0, r = m;
	while (l != r) {
		int mid = (l + r) >> 1;
		check(mid) ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	cout << findMin() << endl;
	cin.ignore(2); return 0;
}