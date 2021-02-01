#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	bool b = false;
	int n; cin >> n;
	int a; cin >> a; v.push_back(a);
	for (int i = 1; i < 2 * n; i++) {
		int c; cin >> c; v.push_back(c);
		if (c != a) { b = true; }
	}
	if (!b) { cout << -1 << endl; }
	else {
		sort(v.begin(), v.end());
		for (int i = 0; i < 2 * n; i++) {
			cout << v[i];
			if (i + 1 != 2 * n) { cout << " "; }
			else { cout << endl; }
		}
	}
	cin.ignore(2); return 0;
}
