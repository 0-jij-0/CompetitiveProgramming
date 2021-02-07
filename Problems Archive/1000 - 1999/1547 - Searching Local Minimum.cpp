#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a[4];

int query(int i, bool b) {
	string c = b ? "!" : "?";
	cout << c + " " + to_string(i + 1) << endl;
	if (!b) { int x; cin >> x; return x; }
	return 0;
}

int main() {
	int n; cin >> n;
	if (n == 1) { return query(0, 1); }
	a[0] = query(0, 0); a[1] = query(1, 0);
	a[2] = query(n - 2, 0); a[3] = query(n - 1, 0);

	if (a[0] < a[1]) { return query(0, 1); }
	if (a[3] < a[2]) { return query(n - 1, 1); }

	int l = 0, r = n - 1; while (r - l > 10) {
		int mid = (l + r) >> 1, m = query(mid, 0);
		int left = query(mid - 1, 0), right = query(mid + 1, 0);
		if (m < left && m < right) { return query(mid, 1); }
		m > left ? r = mid : l = mid;
	}

	vector<int> v(r - l + 1);
	for (int i = l; i <= r; i++)
		v[i - l] = query(i, 0);

	for (int i = 1; i < r - l; i++)
		if (v[i] < v[i - 1] && v[i] < v[i + 1])
			return query(i + l, 1);

	return 0;
}