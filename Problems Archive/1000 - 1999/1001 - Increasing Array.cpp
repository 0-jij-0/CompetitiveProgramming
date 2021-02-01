#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n; vector<int> v(n);
	for (auto &x : v) { cin >> x; }
	int cur = 0; ll res = 0;

	for (auto &x : v) { cur = max(cur, x); res += cur - x; }
	cout << res << endl; cin.ignore(2); return 0;
}