#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v[i] = { a, i + 1 };
	}
	sort(v.rbegin(), v.rend());
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += v[i].first * i + 1;
	}
	cout << res << endl;
	for (auto &x : v) { cout << x.second << ' '; }
	cout << endl; cin.ignore(2); return 0;
}