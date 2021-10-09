#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, p; cin >> n >> p; v.resize(n);
	for (auto& x : v) { cin >> x; }
	int res = 0; for (auto& x : v) res += (x < p);
	cout << res << '\n';
	cin.ignore(2); return 0;
}