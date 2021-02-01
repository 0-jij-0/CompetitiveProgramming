#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int res = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a > k) { v.push_back(i); }
	}
	if (v.empty()) { cout << n << endl; }
	else { cout << v.front() + n - v.back() - 1 << endl; }
	cin.ignore(2); return 0;
}