#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		v.clear(); v.resize(n);
		for (int i = 0; i < n; i++) { cin >> v[i]; }
		sort(v.begin(), v.end());
		int a = v[n - 2];
		if (a < 2) { cout << 0 << endl; }
		else { cout << min(a - 1, n - 2) << endl; }
	}
	cin.ignore(2); return 0;
}