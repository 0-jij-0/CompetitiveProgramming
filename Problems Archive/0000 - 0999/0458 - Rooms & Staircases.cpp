#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		int last = -1, first = -1;
		for (int i = 0; i < n; i++) {
			char c; cin >> c; v[i] = c - '0';
			if (v[i] && first == -1) { first = i; }
			if (v[i]) { last = i; }
		}
		if (first == -1) { cout << n << endl; continue; }
		int a = last + 1 + max(last + 1, n - last);
		int b = n - first + max(n - first, first + 1);
		cout << max(a, b) << endl;
	}
	cin.ignore(2); return 0;
}