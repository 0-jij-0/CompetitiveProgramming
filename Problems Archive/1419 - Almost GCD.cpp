#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p(1000, 0), v;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 2; j * j <= x; j++) {
			if (x % j) { continue; }
			p[j]++; while (x % j == 0) { x /= j; }
		}
		if (x != 1) { p[x]++; }
	}
	cout << max_element(p.begin(), p.end()) - p.begin() << '\n';
	cin.ignore(2); return 0;
}