#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool checkSort(int l ,int r) {
	int n = (int)v.size();
	for (int i = l + 1; i <= r; i++)
		if (v[i] < v[i - 1])
			return false;
	return true;
}

int largestThanos(int l, int r) {
	if (checkSort(l, r)) { return r - l + 1; }
	int mid = (r - l + 1) >> 1;
	int x = largestThanos(l, l + mid - 1);
	int y = largestThanos(l + mid, r);
	return max(x, y);
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	cout << largestThanos(0, n - 1) << endl;
	cin.ignore(2); return 0;
}