#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int i = 1, j = n - 1, a = v[0], b = 0, prevA = v[0], prevB = 0, moves = 1;
		while (true) {
			if (j >= i) { moves++; }
			while (j >= i && prevB <= prevA) { b += v[j]; prevB += v[j]; j--; }
			if (j < i) { break; }
			moves++; prevA = 0;
			while (i <= j && prevA <= prevB) { a += v[i]; prevA += v[i]; i++; }
			if (i > j) { break; }
			prevB = 0;
		}
		cout << moves << ' ' << a << ' ' << b << endl;
	}
	cin.ignore(2); return 0;
}