#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, s; cin >> n >> s; v.resize(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		if (x < s && y != 0) { v[i] = y; continue; }
		if (x < s) { v[i] = 100; continue; }
		if (x == s && y == 0) { v[i] = 100; continue; }
		v[i] = 101;
	}
	int x = *min_element(v.begin(), v.end());
	cout << 100 - x << endl;
	cin.ignore(2); return 0;
}