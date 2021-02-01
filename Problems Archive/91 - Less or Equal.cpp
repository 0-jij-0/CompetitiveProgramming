#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int find_a(int k) {
	sort(v.begin(), v.end());
	if (k == 0 && v[0] <= 1) { return -1; }
	if (k == 0) { return 1; }
	if (v[k - 1] == v[k]) { return -1; }
	return v[k - 1];
}

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	cout << find_a(k) << endl;
	cin.ignore(2); return 0;
}