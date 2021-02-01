#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<bool> c;

int main() {
	int n; cin >> n; v.resize(n); c.resize(n, false);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end()); int res = 0;
	for (int i = 0; i < n; i++) {
		if (c[i]) { continue; }
		res++; c[i] = true;
		for (int j = i + 1; j < n; j++) {
			if (v[j] % v[i] == 0) { c[j] = true; }
		}
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}